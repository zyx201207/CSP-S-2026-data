#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int inf=0x3f3f3f3f,N=500005,K=505;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,n,m,d,q;
ll w[N],ds[K][K];
vector<pair<int,int>> v[N];
void Min(ll &x,ll y){ x=min(x,y); }
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(ds,0x3f,sizeof ds);
	for(int i=1;i<=n;i++) ds[i][i]=0;
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1,p,t;j<=k;j++){
			cin>>p>>t;
			for(auto [x,y]:v[p])
				Min(ds[i][x],t+y),Min(ds[x][i],t+y);
			v[p].pb({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				Min(ds[i][j],ds[i][k]+ds[k][j]);
	}
	for(int x,y;q--;){
		cin>>x>>y;
		ll ans=INF;
		for(auto [i,ti]:v[x])
			for(auto [j,tj]:v[y])
				Min(ans,ds[i][j]+ti+tj);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}