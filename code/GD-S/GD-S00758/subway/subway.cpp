#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pil pair<int,ll>
#define e_b emplace_back
#define zzz ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int N=5e5+5,P=505;
const ll inf=2e18;
int n,m,d,q;
ll g[P][P],w[N];
vector<pil>E[N];
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i^j)g[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		while(k--){
			int a;ll t;cin>>a>>t;
			E[a].e_b(i,t);
		}
	}
	for(int p=1;p<=m;p++){
		int sz=E[p].size();
		for(int i=0;i<sz;i++)
			for(int j=i;j<sz;j++){
				int u=E[p][i].fir,v=E[p][j].fir;
				ll uw=E[p][i].sec,vw=E[p][j].sec;
				g[u][v]=g[v][u]=min(g[u][v],uw+vw);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//	for(int i=1;i<=n;i++){
//		//cout<<i<<' '<<j<<'\n';
//		for(int j=i;j<=n;j++)
//			cout<<g[i][j]<<' ';
//		cout<<'\n';
//	}
	while(q--){
		int x,y;
		ll mi=inf;
		cin>>x>>y;
		for(pil tmp1:E[x]){
			int u=tmp1.fir;ll xw=tmp1.sec;
			for(pil tmp2:E[y]){
				int v=tmp2.fir;ll yw=tmp2.sec;
				mi=min(mi,g[u][v]+xw+yw);
			}
		}
		ll ans=mi+w[x]+w[y];
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	zzz;cin>>c;
	solve();
}

