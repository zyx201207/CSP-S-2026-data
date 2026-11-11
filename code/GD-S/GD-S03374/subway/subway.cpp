#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define EB emplace_back
typedef long long ll;
typedef pair<int,ll> PII;
const int N=500+5,M=5e5+5;
const ll INF=1e16;
int c,n,m,d,q;
vector<PII> g[M];
ll dis[N][N],w[M];
void lian(int i){
	int l=g[i].size();
//	cout<<"debugC"<<i<<endl;
//	for(PII x:g[i])cout<<x.x<<' ';
//	cout<<endl;
	for(int k=0;k<l;k++){
		PII cur1=g[i][k];
		ll u=cur1.x,w1=cur1.y;
		for(int j=k+1;j<l;j++){
			PII cur2=g[i][j];
			ll v=cur2.x,w2=cur2.y;
//			cout<<"debugB"<<u<<' '<<v<<' ';
//			cout<<w1<<' '<<w2<<endl;
			dis[u][v]=dis[v][u]=min(dis[u][v],w1+w2);
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i==j)continue;
		if(dis[i][j]>dis[i][k]+dis[k][j]){
			dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k,v,w;i<=n;i++){
		cin>>k;
		while(k--){
			cin>>v>>w;
			g[v].EB(i,w);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		dis[i][j]=INF;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		lian(i);
	}
	floyd();
	while(q--){
		int u,v;
		ll ans=INF;
		cin>>u>>v;
		for(PII a:g[u])
		for(PII b:g[v]){
			ans=min(ans,a.y+b.y+dis[a.x][b.x]);
//			cout<<"debugA"<<a.x<<' '<<b.x<<"\ndis:"<<dis[a.x][b.x]<<endl;
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}

