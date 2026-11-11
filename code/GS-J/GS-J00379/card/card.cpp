#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005], t[300005], vis[300005];
int main(){
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	int n, m, f = 0, xb = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
		memset(b, 0, sizeof(b));
		for(int j = i; j <= n; j++){
			b[j] = a[j];
			for(int k = 1; k <= j; k++){
				if(b[k] == b[j]){
					f = 1;
					xb = k + 1;
					break;
				}
			}
			if(f){
				for(int k = xb; k <= j; k++){
					b[k] = 0;
				}
			}
		}
		for(int j = i; j <= n; j++){
			if(b[j] && vis[b[j]] == 0){
				t[b[j]]++;
				vis[b[j]] = 1;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << t[i] << ' ';
	}
	return 0;
}


