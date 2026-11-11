#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,w;
};
int c,n,m,d,Q,W[500005],k,a[500005],t[500005],dis[500005];
priority_queue<pair<int,int>> q;
vector<node> g[500005];
bool v[500005];
void dj(int sx){
	q.push({0,sx});
	while(!q.empty()){
		int u=q.top().second,s=-q.top().first;
		q.pop();
		if(v[u]) continue;
		v[u]=1;
		for(auto gi:g[u]){
			if(dis[gi.x]>dis[u]+gi.w){
				dis[gi.x]=dis[u]+gi.w;
				q.push({-dis[gi.x],gi.x});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&W[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld %lld",&a[j],&t[j]);
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				g[a[u]].push_back({a[v],t[u]+t[v]});
				g[a[v]].push_back({a[u],t[u]+t[v]});
			}
		}
	}
	while(Q--){
		memset(v,0,sizeof v);
		memset(dis,0x7f,sizeof dis);
		int sx,sy;
		scanf("%lld %lld",&sx,&sy);
		dis[sx]=0;
		dj(sx);
		int ans=dis[sy]+W[sx]+W[sy];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32 17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
