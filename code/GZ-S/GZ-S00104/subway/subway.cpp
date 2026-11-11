//GZ-S00104 贵阳市第一中学 胡源宸 
#include<bits/stdc++.h>
#define ll long long
#define ls i<<1
#define rs i<<1|1
#define pii pair<ll,ll>
#define pb push_back
using namespace std;
const int N=500+10,M=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll T,c,n,m,dw,q,d[N][N],k[N],w[M],a[M],t[M],ans;
vector<pii>G[M];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	return;
}
void solve(){
	cin>>c>>n>>m>>dw>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			G[a[j]].pb({i,t[j]});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pii h1:G[i]){
			for(pii h2:G[i]){
				if(h1==h2) continue;
				d[h1.first][h2.first]=min(d[h1.first][h2.first],h1.second+h2.second);
			}
		}
	}
	floyd();
	while(q--){
		ll u,v;
		cin>>u>>v;
		ans=INF;
		for(pii h1:G[u]){
			for(pii h2:G[v]){
				ans=min(ans,d[h1.first][h2.first]+h1.second+h2.second);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	cin.tie(nullptr);
	freopen("subway.out","w",stdout);
	T=1;
	while(T--){
		solve();
	}
	return 0;
}
