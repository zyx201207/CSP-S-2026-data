#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], b[500010], ans[500010];
bool vis[500010];
int main(){
	freopen("card.in","r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		memset(b, 0, sizeof(b));
		memset(vis,0, sizeof(vis));
		int cnt = 0;
		for(int j = i; j <= n; j++){
			bool flag = 0;
			for(int k = 1; k <= cnt; k++){
				if(a[j] == b[k]){
					for(int l = k+1; l <= cnt; l++){
						b[l] = 0;
					}
					cnt = k;
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				b[++cnt] = a[j];
			}
		}
		for(int j = 1; j <= cnt; j++){
			if(vis[b[j]] == 0){
				vis[b[j]] = 1;
				ans[b[j]]++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
