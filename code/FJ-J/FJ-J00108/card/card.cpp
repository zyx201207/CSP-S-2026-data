#include <bits\stdc++.h>
using namespace std;
int a[500050], b[500050], c[300050];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int j = 1; j<=n; j++){
		for(int i = 1; i<=n; i++){
			b[i] = a[i];
		}
		for(int i = 1; i<=j-1; i++){
			b[i] = 0;
		}
		for(int i = 1; i<=n; i++){
			for(int k = 1; k<i; k++){
				if(b[k]==b[i]){
					for(int p = k; p<i; p++){
						b[p] = 0;
					}
				}
			}
		}
		for(int i = 1; i<=n; i++){
			c[b[i]]++;
		}
	}
	for(int i = 1; i<=m; i++){
		cout << c[i] << " ";
	}
	return 0;
}
