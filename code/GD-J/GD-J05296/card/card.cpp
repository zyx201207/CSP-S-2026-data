#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5e5 + 1, M = 3e5 + 1;
int n, m, a[N];
int s[N], to[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = a[i];
	}
	for(int t = 1; t <= n; t++){
		for(int i = t; i <= n; i++){
			int tmp = a[i];
			for(int j = 1; j <= n; j++){
				if(a[j] == tmp){
					for(int k = j; k <= n; k++){
						a[k] = 0;
					}
					a[j] = tmp;
				}else{
					n++;
					a[n] = tmp;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			to[a[i]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << to[i] << ' ';
	}
	return 0;
}
