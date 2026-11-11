#include <bits/stdc++.h>
using namespace std;

long long n, m, s[500005], ans[300005], vis[300005], now[500005]; 

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n; i++)  cin >> s[i];
	for(int i = 1;i <= n; i++){
		long long cut = 0;
		memset(vis, 0, sizeof(vis));
		for(int j = i;j <= n; j++){
			if(vis[s[j]] >= 1){
				while(now[cut] != s[j])  cut--;
			}else{
				cut++;
				now[cut] = s[j];
				vis[s[j]]++;
			}
		}
		for(int i = 1;i <= cut; i++)  ans[now[i]]++;
	}
	
	for(int i = 1;i <= m; i++)  cout << ans[i] << " ";
	
	return 0;
}
