#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n,m,a[500005],b[300005] = {},c[500005] = {};
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int r = 1;
	for (int v = 1; v <= n; v++){
		r = 1;
		for (int i = v; i <= n; i++){
			for (int j = 1; j <= r; j++){
				if (c[j] == a[i]){
					for (int k = j; k <= r; k++){
						c[k] = 0;
					}
					r = j;
					break;
				}
			}
			c[r] = a[i];
			r++;
		}
		for (int i = 1; i <= r; i++){
			b[c[i]]++;
		}
		for (int i = 1; i <= r; i++){
			c[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << b[i] << ' ';
	}
	return 0;
}
