#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], maxx;
bool vis[100005];

inline void dfs(int x, int num, int cnt){
	if(cnt == m + 1){
		maxx = max(num, maxx);
		return;
	}
	if(!vis[x]){
		num &= a[x];
	}
	vis[x + 1] = 1;
	dfs(x + 1, num, cnt++);
	vis[x + 1] = 0;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
//	dfs(1, 1, 0);
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxx = max(maxx, 1 & a[i]);
		}
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				maxx = max(maxx, a[i] & a[j]);
			}
		}	
	}
	if(m == 3){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					maxx = max(maxx, a[i] & a[j] & a[k]);
				}
			}
		}
	}
	if(m == 4){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						maxx = max(maxx, a[i] & a[j] & a[k] & a[l]);
					}
				}
			}
		}
	}
	if(m == 5){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int m = l + 1;m <= n;m++){
							maxx = max(maxx, a[m] & a[i] & a[j] & a[k] & a[l]);
						}
					}
				}
			}
		}
	}
	if(m == 6){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				for(int k = j + 1;k <= n;k++){
					for(int l = k + 1;l <= n;l++){
						for(int m = l + 1;m <= n;m++){
							for(int v = m + 1;v <= n;v++){
								maxx = max(maxx, a[v] & a[m] & a[i] & a[j] & a[k] & a[l]);
							}
						}
					}
				}
			}
		}
	}
	cout << maxx;
	
	return 0;
}

