#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=5e5+10;
ll a[N],dis[510][510],mp[510][510];
bool v[510];
vector<pair<int,ll>> G[N],G2[510];
priority_queue<pii,vector<pii>,greater<pii>> q;
void dijkstra(int st){
	memset(dis[st],63,sizeof(dis[st]));
	memset(v,0,sizeof(v));
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(auto i:G2[x]){
			int y=i.first;
			ll z=i.second;
			if(dis[st][y]>dis[st][x]+z){
				dis[st][y]=dis[st][x]+z;
				q.push({dis[st][y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,_;
	scanf("%d%d%d%d%d",&n,&n,&m,&d,&_);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int __;
		scanf("%d",&__);
		while(__--){
			int x;
			ll y;
			scanf("%d%lld",&x,&y);
			G[x].push_back({i,y});
		}
	}
	memset(mp,63,sizeof(mp));
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=j+1;k<G[i].size();k++){
				int xa=G[i][j].first,xb=G[i][k].first;
				ll ya=G[i][j].second,yb=G[i][k].second;
				mp[xa][xb]=mp[xb][xa]=min(mp[xa][xb],ya+yb);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&mp[i][j]<1e18)G2[i].push_back({j,mp[i][j]});
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	while(_--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=9e18;
		for(int i=0;i<G[x].size();i++){
			for(int j=0;j<G[y].size();j++){
				int xa=G[x][i].first,xb=G[y][j].first;
				ll ya=G[x][i].second,yb=G[y][j].second;
				ans=min(ans,a[x]+a[y]+ya+yb+dis[xa][xb]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
