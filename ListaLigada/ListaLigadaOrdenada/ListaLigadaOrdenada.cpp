#include <iostream>
using namespace std;

// definição de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElementoOrdenado();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada Ordenada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElementoOrdenado();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

// Inserir elemento em ordem e evitar duplicatas
void inserirElementoOrdenado()
{
	int valor;
	cout << "Digite o elemento: ";
	cin >> valor;

	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}
	novo->valor = valor;
	novo->prox = NULL;

	// Se a lista estiver vazia ou o valor for menor que o primeiro valor
	if (primeiro == NULL || primeiro->valor > valor) {
		novo->prox = primeiro;
		primeiro = novo;
	}
	else {
		NO* atual = primeiro;
		NO* anterior = NULL;

		// Percorrer a lista para encontrar a posição correta
		while (atual != NULL && atual->valor < valor) {
			anterior = atual;
			atual = atual->prox;
		}

		// Se o elemento já existir na lista, não insere duplicado
		if (atual != NULL && atual->valor == valor) {
			cout << "Elemento já existe na lista. Não será inserido.\n";
			free(novo); // Libera a memória alocada para o novo nó
			return;
		}

		// Insere o novo elemento na posição correta
		anterior->prox = novo;
		novo->prox = atual;
	}
	cout << "Elemento inserido.\n";
}

// Função otimizada para excluir elemento em lista ordenada
void excluirElemento()
{
	int valor;
	cout << "Digite o valor a ser excluído: ";
	cin >> valor;

	if (primeiro == NULL) {
		cout << "Lista vazia. Nenhum elemento para excluir.\n";
		return;
	}

	NO* atual = primeiro;
	NO* anterior = NULL;

	// Encontrar o elemento a ser excluído
	while (atual != NULL && atual->valor != valor) {
		anterior = atual;
		atual = atual->prox;
	}

	// Elemento não encontrado
	if (atual == NULL) {
		cout << "Elemento não encontrado.\n";
		return;
	}

	// Remover o elemento
	if (anterior == NULL) {
		primeiro = atual->prox; // Remover o primeiro elemento
	}
	else {
		anterior->prox = atual->prox; // Remover qualquer outro elemento
	}

	free(atual);
	cout << "Elemento excluído.\n";
}

// Função otimizada para buscar elemento em lista ordenada
void buscarElemento()
{
	int valor;
	cout << "Digite o valor a ser buscado: ";
	cin >> valor;

	NO* atual = primeiro;

	// Percorrer a lista até encontrar o elemento ou até ultrapassar o valor
	while (atual != NULL && atual->valor <= valor) {
		if (atual->valor == valor) {
			cout << "Elemento encontrado: " << valor << endl;
			return;
		}
		atual = atual->prox;
	}

	cout << "Elemento não encontrado.\n";
}
