#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500500],k[550],dis[1010];
vector <int> a[550];
vector <int> t[550];
vector <pair <int,int> > v[1010];
vector <pair <int,int> > e[1010];
inline int dijkstra(int s,int e){
	queue <int> q;
	q.push(s);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<v[u].size();i++){
			if(dis[u]+t[v[u][i].second][1]+t[v[u][i].second][2]<dis[v[u][i].first]){
				dis[v[u][i].first]=dis[u]+t[v[u][i].second][1]+t[v[u][i].second][2];
				q.push(v[u][i].first);
			}
		}
	}
	return dis[e]+w[s]+w[e];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		if(k[i]==1){
			i--;
			continue;
		}
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<k[i];j++){
			v[a[i][j]].push_back({a[i][j+1],i});
			v[a[i][j+1]].push_back({a[i][j],i});
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dijkstra(x,y));
	}
	return 0;
}

