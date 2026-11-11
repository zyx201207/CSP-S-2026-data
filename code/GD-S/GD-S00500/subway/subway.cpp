#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5;
ll c,n,m,d,q,a[N+10],k,u,t,w[N+10][21],d2[N+10],h[N+10][21],vis[N+10],D[510][510],D2[510][510],x,y,mi,ans,INF;
struct node{
	ll to,dis;
};
vector<node> e[510];
typedef pair<ll,ll> PII;
priority_queue<PII,vector<PII>,greater<PII> > p;
void dijkstra(ll s) {
	D[s][s]=0;
	p.push(PII(0,s));
	memset(vis,0,sizeof vis);
	while(!p.empty()) {
		int u=p.top().second;
		p.pop(); 
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++) {
			ll v=e[u][i].to,w=e[u][i].dis;
			if(D[s][v]>D[s][u]+w) {
				D[s][v]=D[s][u]+w;
				p.push(PII(D[s][v],v));
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>u>>t;
			++d2[u];
			h[u][d2[u]]=i;
			w[u][d2[u]]=t;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++)
			D[i][j]=1e18,D2[i][j]=1e18;
	}
	INF=1e18;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=d2[i];j++) {
			for(int g=j+1;g<=d2[i];g++) {
				ll s=w[i][j]+w[i][g];
				if(s<D2[h[i][j]][h[i][g]]&&s<D2[h[i][g]][h[i][j]]) D2[h[i][j]][h[i][g]]=s,D2[h[i][g]][h[i][j]]=s;
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(D2[i][j]<INF) {
				e[i].push_back({j,D2[i][j]});
				e[j].push_back({i,D2[i][j]});
			}
		}
	} 			
	for(int i=1;i<=n;i++) 
		dijkstra(i);
	for(int i=1;i<=q;i++) {
		cin>>x>>y;
		ans=0,mi=1e18;
		for(int j=1;j<=d2[x];j++) {
			for(int g=1;g<=d2[y];g++) {
				ans=a[x]+a[y]+w[x][j]+w[y][g]+D[h[x][j]][h[y][g]];
				mi=min(mi,ans);
			}
		}
		cout<<mi<<"\n";
	}
	
	return 0;
} 
