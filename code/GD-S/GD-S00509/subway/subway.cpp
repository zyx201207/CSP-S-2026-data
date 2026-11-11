#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[505],dis[1005][1005],tmp[500005],g[1005][1005],t[500005];
int hsh(int a,int b){
	return (a << 30) + b;
}
int c,n,m,d,q;
void dij(int st){
	priority_queue<pair<int,int> > q;
	q.push({0,st});
	dis[st][st] = 0;
	while(!q.empty()){
		int t = -q.top().first,id = q.top().second;
		q.pop();
		for (int i = 1;i <= m;i++){
			if(i == id || g[id][i] >= 1e18) continue;
			if (dis[st][id] + g[id][i] < dis[st][i]){
				dis[st][i] = dis[st][id] + g[id][i];
				q.push({-dis[st][i],i});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for (int i = 1;i <= 1000;i++)
		for (int j = 1;j <= 1000;j++)
			g[i][j] = dis[i][j] = 1e18;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++){
		int l;
		cin >> l;
		for (int j = 1;j <= l;j++)
			cin >> tmp[j] >> t[j];
		for (int j = 1;j <= l;j++){
			for (int k = 1;k <= l;k++){
				if(j == k) continue;
				g[tmp[k]][tmp[j]] = min(g[tmp[j]][tmp[k]],t[j] + t[k]);
			}
		}
	}
	for (int i = 1;i <= m;i++)
		dij(i);
	while(q--){
		int u,v;
		cin >> u >> v;
		printf("%lld\n",min(dis[u][v],dis[v][u]) + w[u] + w[v]);
	}
	return 0;
}
