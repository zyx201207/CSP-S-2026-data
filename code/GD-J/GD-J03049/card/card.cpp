#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100001], c[100001];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		int b[10001] = {0};
		for (int j = i;j <= n;j++){
			if (b[a[j]] != 0){
				for (int k = b[a[j]]; k <= j;k++){
					b[a[k]] = 0;
				}
			}
			b[a[j]] = j;
		}
		for (int j = m;j >= 1;j--){
			if (b[j] != 0){
				c[j]++;
			}
		}
	}
	for (int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
} 
