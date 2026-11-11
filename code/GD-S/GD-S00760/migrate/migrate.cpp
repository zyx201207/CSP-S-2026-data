#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
//多测记得清空 
int read(){
	int dat = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) dat = dat * 10 + (c - '0');
	return dat * f; 
}
int n,d,a[N],_,ne[N],dis[N],vis[N];
void solve(){
	n = read(),d = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int idx = n,ans = 0;
	for(int i = n; i >= 1; i--){
		while(a[idx] > a[i] + d) --idx;
		ne[i] = idx;
	}
	for(int i = 1; i <= n; i++){
		queue <int> q;while(!q.empty()) q.pop();
		q.push(i);
		for(int j = i; j <= n; j++) vis[j] = 0,dis[j] = 0x3f3f3f3f;
		dis[i] = 0;
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int j = x + 1; j <= ne[x]; j++){
				if(dis[j] > dis[x] + 1){
					vis[j] = 1;
					dis[j] = dis[x] + 1;
					q.push(j);
				}
				else if(dis[j] == dis[x] + 1) vis[j]++;
			}
		}
		for(int j = i + 1; j <= n; j++){
			if(vis[j] == 2) ++ans;
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	_ = read();int T = read();
	while(T--) solve();
	return 0;
}
