#include <bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e5+ 5;
const long long inf = 1ll << 60;
int c,n,m,d,q;
long long w[M];
int k[N];
vector <long long> a[N],t[N];
vector <long long> b[M],s[M];
long long u,v,dis[N][N],mp[N][N],ans,now;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m; i++) scanf("%lld",&w[i]);
	for(int i = 1; i <= n; i++){
		scanf("%d",&k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%lld%lld",&u,&v);
			a[i].push_back(u),t[i].push_back(v);
			b[u].push_back(i),s[u].push_back(v);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) mp[i][j] = dis[i][j] = inf;
		mp[i][i] = 0,dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < b[i].size(); j++){
			for(int l = 0; l < j; l++) mp[b[i][j]][b[i][l]] = mp[b[i][l]][b[i][j]] = min(mp[b[i][j]][b[i][l]],s[i][j] + s[i][l]);
		}
	}
	for(u = 1; u <= n; u++){
		for(v = 1; v <= n; v++) dis[u][v] = mp[u][v];
	}
	for(u = 1; u <= n; u++){
		for(v = 1; v <= n; v++){
			for(int i = 1; i <= n; i++) dis[u][v] = min(dis[u][v],dis[u][i] + dis[i][v]);
		}
	}
	for(int _ = 1; _ <= q; _++){
		scanf("%lld%lld",&u,&v);
		ans = inf;
		for(int i = 0; i < b[u].size(); i++){
			for(int j = 0; j < b[v].size(); j++){
				now = dis[b[u][i]][b[v][j]] + s[u][i] + s[v][j];
				ans = min(ans,now);
			}
		}
		ans += w[u] + w[v];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
