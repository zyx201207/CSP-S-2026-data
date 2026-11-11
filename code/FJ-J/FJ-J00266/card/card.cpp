#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define fin cin
#define fout cout
int n, m;
int main(){
//	fstream fin("card.in");
//	fstream fout("card.out");
	cin >> n >> m;
	vector<int> cards(n);
	vector<int> cards_cpy(n);
	for (int i = 0; i < n; i++){
		fin >> cards[i];
		cards_cpy[i] = cards[i];
	}
	for (int i = 1; i <= m; i++){
		for (int j = i; j <= m; j++){
			
		}
	}
//	fin.close(); fout.close();
	return 0;
}
