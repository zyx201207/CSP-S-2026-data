#include <iostream>
#include <cstdio>
using namespace std;
int cad[20000], _cad[20000];
int top = 1;
int n, m;
int ans[20000][10000];
bool check(int p){
	for(int i = 1;i < top;i++){
		if(cad[i] == p){
			return 1;
		}
	}
	return 0;
}
int find(int p){
	for(int i = 1;i < top;i++){
		if(cad[i] == p){
			return i;
		}
	}
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> cad[top];
		_cad[top] = cad[top];
		top++;
	}
	int len = top;
	for(int i = 1;i <= n;i++){
		int giv[20000];
		top = 1;
		for(int j = i;j <= n;j++){
			giv[j - i + 1] = cad[j];
		}
		for(int j = 1;j <= n-i+1;j++){
			if(check(giv[j])){
				top = find(giv[j])+1;
			}else{
				cad[top] = giv[j];
				top++;
			}
		}
		for(int j = 1;j < top;j++){
			ans[i][cad[j]]++;
		}
		for(int j = 1;j < len;j++){
			cad[j] = _cad[j];
		}
		top = len;
	}
	for(int i = 1;i <= m;i++){
		int las = 0;
		for(int j = 1;j <= n;j++){
			if(ans[j][i] != 0){
				las++;
			}
		}
		cout << las << " ";
	}
	return 0;
}
