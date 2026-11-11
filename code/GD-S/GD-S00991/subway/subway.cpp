#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N=5e5+10,M=510;
vector<pii>G[N+M];
ll dis[N+M],tp[M][M],ans[100010];
int wv[N],n,m,d,q,cnt[M],vis[M],len,v[N+M];
set<int>fa[N];
map<int,ll>t[N];
struct E{
	int x,y;
}Q[100010];
void dij(int st){
	for(int i=1;i<=n+m;i++) dis[i]=LONG_LONG_MAX;dis[st]=0;
	memset(v,0,sizeof v);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,st});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(auto i:G[x]){
			int y=i.first,w=i.second;
			if(y>n&&dis[x]) w+=t[y-n][x];
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				if(y<=n) q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&wv[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1,x,tt;j<=k;j++){
			scanf("%d%d",&x,&tt);
			t[x][i]=tt;
			G[i].push_back({x+n,0});
			fa[x].insert(i);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tp[i][j]=1e18;
	for(int i=1;i<=m;i++) if(fa[i].size()>1){
		for(auto x:fa[i]) for(auto y:fa[i]) if(x!=y){
			tp[x][y]=tp[y][x]=min(tp[x][y],t[i][x]+t[i][y]);
		}
	}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(tp[i][j]!=1e18){
		G[i].push_back({j,tp[i][j]});
		G[j].push_back({i,tp[i][j]});
	}
	for(int i=1;i<=q;i++){
		cin>>Q[i].x>>Q[i].y;
		for(auto y:fa[Q[i].x]) if(!vis[y]){
			vis[y]=1;
			cnt[++len]=y;
		}
	}
	sort(cnt+1,cnt+len+1);
	for(int i=1;i<=q;i++) ans[i]=LONG_LONG_MAX;
	for(int i=1;i<=len;i++){
		dij(cnt[i]);
//		for(int j=1;j<=n+m;j++) printf("%lld\n",dis[j]);
		for(int j=1;j<=q;j++){
			int X=Q[j].x,Y=Q[j].y;
			if(fa[X].find(cnt[i])!=fa[X].end()){
				ans[j]=min(ans[j],dis[Y+n]+wv[X]+wv[Y]+t[X][cnt[i]]+t[Y][cnt[i]]);
			}
		}
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	
	return 0;
}
