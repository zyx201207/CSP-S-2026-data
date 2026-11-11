#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 250;
int a[N], b[N], c[N];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		for(int j = i; j <= n; j++){
			int h = 0;
			int g = 0;
			for(int k = i; k <= j - 1; k++){
				if(b[k] == a[j]){
					h = 1;
					g = k;
					break;
				}
			}
			b[j] = a[j];
			if(h == 1){
				for(int k = g; k <= j - 1; k++){
					b[k] = 0;
				}
			}
		}
		for(int j = i; j <= n; j++){
			if(b[j] != 0){
				c[b[j]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << c[i] << " ";
	}
	return 0;
}
