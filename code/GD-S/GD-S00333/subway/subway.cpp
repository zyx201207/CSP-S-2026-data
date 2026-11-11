#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int maxn=502,maxm=500002;
const ll lnf=1e18+1121;
int c_,n,m,d,q;
int jiw[maxm];
vector <pii> a[maxm];
ll dis[maxn][maxn];
inline void chkn(ll &x,ll y){x=min(x,y);}
inline void upd(int u,int v,ll w){dis[u][v]=dis[v][u]=min(dis[u][v],w);}
void Solve(){
	cin>>c_>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>jiw[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,t;j<=k;j++){
			cin>>u>>t;
			a[u].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=lnf;
		dis[i][i]=0;
	}
	for(int u=1;u<=m;u++){
		const int N=a[u].size();
		for(int i=1;i<N;i++) for(int j=0;j<i;j++) upd(a[u][i].fi,a[u][j].fi,a[u][i].se+a[u][j].se);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chkn(dis[i][j],dis[i][k]+dis[k][j]);
	for(int tokuno=1,u,v;tokuno<=q;tokuno++){
		cin>>u>>v;
		ll res=lnf;
		for(pii i:a[u]) for(pii j:a[v]) chkn(res,i.se+j.se+dis[i.fi][j.fi]);
		res+=jiw[u]+jiw[v];
		cout<<res<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Solve();
	return 0;
}

