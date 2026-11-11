#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
namespace FastIO{
	inline ll read(){
		ll s=0,f=1;char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}while('0'<=c&&c<='9'){
			s=(s<<1)+(s<<3)+c-'0';
			c=getchar();
		}return s*f;
	}
}
using FastIO::read;

typedef pair<ll,int> pa;
const int N = 515;
const int NN = 30;
const int M = 500500;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,dd,q;
ll w[M];
int k[N],tg[N],a[M],gnt[M];
ll t[M],dis[N][N];
pa bel[M][NN];

struct line{
	int Nxt,to;ll val;
}l[M];//<=25w
int h[N],cnt;
void link(int u,int v,ll val){
	l[++cnt]=(line){h[u],v,val};h[u]=cnt;
	l[++cnt]=(line){h[v],u,val};h[v]=cnt;
}
ll d[N][N],vis[N][N];
priority_queue<pa,vector<pa>,greater<pa> > s;//test
void Dijkstra(int S){
	for(int i=1;i<=n;i++)d[S][i]=inf;
	d[S][S]=0;
	s.push({0,S});
	while(!s.empty()){
		int u=s.top().second;s.pop();
		if(vis[S][u])continue;
		vis[S][u]=1;
		for(int i=h[u],v;i;i=l[i].Nxt){
			v=l[i].to;
			if(d[S][v]>d[S][u]+l[i].val){
				d[S][v]=d[S][u]+l[i].val;
				s.push({d[S][v],v});
			}
		}
	}
	
}
int xr,yr;
ll ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(gnt,0,sizeof(gnt));
	c=read(),n=read(),m=read(),dd=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		tg[i]=k[i]+tg[i-1];
		for(int j=1;j<=k[i];j++){
			a[tg[i-1]+j]=read();
			t[tg[i-1]+j]=read();
			//cout<<n<<' '<<m<<' '<<i<<' '<<k[i]<<' '<<a[tg[i-1]+j]<<' '<<gnt[a[tg[i-1]+j]]<<'\n';
			gnt[a[tg[i-1]+j]]++;
			bel[a[tg[i-1]+j]][gnt[a[tg[i-1]+j]]].first=t[tg[i-1]+j];//position
			bel[a[tg[i-1]+j]][gnt[a[tg[i-1]+j]]].second=i; 
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=gnt[i];j++){
			for(int w=j+1;w<=gnt[i];w++){
				dis[bel[i][j].second][bel[i][w].second]=min(dis[bel[i][j].second][bel[i][w].second],bel[i][j].first+bel[i][w].first);
				dis[bel[i][w].second][bel[i][j].second]=dis[bel[i][j].second][bel[i][w].second];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]!=inf)link(i,j,dis[i][j]);
		}
	}
	for(int i=1;i<=n;i++)Dijkstra(i);
//	cout<<"PRINT DISTANCE:\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<d[i][j]<<' ';
//		}cout<<'\n';
//	}
	while(q--){
		xr=read(),yr=read();ans=inf;
		for(int i=1;i<=gnt[xr];i++){
			for(int j=1;j<=gnt[yr];j++){
				//cout<<bel[xr][i].first<<' '<<bel[yr][j].first<<' '<<d[bel[xr][i].second][bel[yr][j].second]<<'\n';
				ans=min(ans,d[bel[xr][i].second][bel[yr][j].second]+bel[xr][i].first+bel[yr][j].first);
			}
		}
		ans+=w[xr]+w[yr];
		cout<<ans<<'\n';
	}
	return 0;
}
