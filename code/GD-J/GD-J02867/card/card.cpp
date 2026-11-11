#include<bits/stdc++.h>
using namespace std;
int cnt[100010];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[500010];
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int r = n, i = 1;
	while(r--){
		int s = 1;
		int b[12910];
		for (int j = n-r; j <= n; j++){
			b[s] = a[j];
			for (int k = 1; k <= n; k++){ 
				if (b[k] == a[j]){
					s = k;
					break;
				}
			}
			s++;
		}
		for (int p = 1; p <= m; p++){
			for (int q = 1; q < s; q++){
				if (b[q] == p) {
					cnt[p]++;
					break;
				}
			}
		}
	}
	for (int t = 1; t <= m; t++){
		cout << cnt[t] << ' ';
	}
	
	return 0;
} 


