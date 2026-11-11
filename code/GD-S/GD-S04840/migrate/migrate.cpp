#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<long long>g[5005];
long long c, t, n, d, x[200005], f[5005], ans[5005];
bool vis[5005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	if(c <= 10){
		while(t--){
			scanf("%lld%lld", &n, &d);
			for(int i = 1; i <= n; i++){
				scanf("%lld", &x[i]);
				g[i].resize(0);
			}
			for(int i = 1; i <= n; i++){
				long long k = upper_bound(x + 1, x + n + 1, x[i] + d) - x;
				k = min(k - 1, n);
				for(int j = i + 1; j <= k; j++){
					g[i].push_back(j);
				}
			}
			int t = 0;
			for(int i = 1; i <= n; i++){
				memset(f, 0x3f, sizeof f);
				memset(ans, 0, sizeof ans);
				memset(vis, 0, sizeof vis);
				queue<int>q;
				q.push(i);
				f[i] = 0, ans[i] = 1, vis[i] = 1;
				while(!q.empty()){
					int u = q.front();
					q.pop();
					vis[u] = 0;
					for(int v:g[u]){
						if(f[u] + 1 < f[v]){
							f[v] = f[u] + 1;
							ans[v] = ans[u];
							if(!vis[v])q.push(v);
							vis[v] = 1;
						}
						else if(f[u] + 1 == f[v]){
							ans[v] += ans[u];
						}
					}
				}
				for(int j = 1; j <= n; j++){
					if(ans[j] == 2)t++;
				}
			}
			printf("%lld\n", t);
		}
	}
}
