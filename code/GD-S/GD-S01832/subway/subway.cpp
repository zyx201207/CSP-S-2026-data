#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define fir first
#define sec second
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;
int cs,n,m,d,q;
//编号,线路数量,站台数量,每个站台最多被几个线路过,询问数量 
int h[N],e[M],ne[M],idx;
ll W[M],w[M];
int k[N];
ll Dis[N][N],vis[N];
vector<pii> ve[M]; //站台路程,几号线 
ll leng[N][N];
void add(int x,int y,ll z) {
	e[idx]=y,w[idx]=z,ne[idx]=h[x],h[x]=idx++;
}
void dij(int sx,ll* dis) {
	priority_queue<pii,vector<pii>,greater<pii> >que;
	que.push({0,sx});
	for (int i=1;i<N;i++) {
		dis[i]=6e18,vis[i]=0;
	}
	dis[sx]=0;
	while (!que.empty()) {
		int u=que.top().sec;
		que.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=h[u];~i;i=ne[i]) {
			int v=e[i];
			if (dis[v]>dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
				que.push({dis[v],v});
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(leng,0x3f,sizeof leng);
	memset(h,-1,sizeof h);
	scanf("%d %d %d %d %d",&cs,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) {
		scanf("%lld",&W[i]);
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&k[i]);
		int last=0;
		for (int j=1;j<=k[i];j++) {
			int to;
			ll time;
			scanf("%d %lld",&to,&time);
			ve[to].push_back({time,i});
		}
	}
	for (int i=1;i<=m;i++) {
		int len=ve[i].size();
		if (len<=1) continue;
		for (int j=0;j<len-1;j++) {
			for (int l=j+1;l<len;l++) {
				int x=ve[i][j].sec;
				int y=ve[i][l].sec;
				leng[x][y]=min(leng[x][y],ve[i][j].fir+ve[i][l].fir);
				leng[y][x]=min(leng[x][y],leng[y][x]);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (i==j) continue;
			add(i,j,leng[i][j]);
		}
	}
	for (int i=1;i<=n;i++) {
		dij(i,Dis[i]);
	}
	for (int i=1;i<=q;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		ll ans=6e18;
		for (auto j:ve[x]) {
			for (auto l:ve[y]) {
				ans=min(ans,Dis[j.sec][l.sec]+j.fir+l.fir);
			}
		}
		printf("%lld\n",ans+W[x]+W[y]);
	}
	return 0;
}
