#include<bits/stdc++.h>
#define ll long long
#define fs first
#define sc second
using namespace std;
const int N=5e5+5;
ll c,n,m,d,q,w[N],k[505],f[505][505];
vector<ll> a[505],t[505];
vector<pair<ll,ll>> G[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			a[i].reserve(k[i]+1);
			t[i].reserve(k[i]+1);
			cin>>a[i][j]>>t[i][j];
			G[a[i][j]].push_back({i,t[i][j]});
		}
	}
	/*for(int i=1;i<=m;i++){
		for(auto p : G[i]) cout<<p.fs<<' '<<p.sc<<'\n';
		cout<<'\n';
	}*//*OK*/
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) f[i][j]=1e18;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			int x=a[i][j];
			for(auto p : G[x]){
				int v=p.fs;
				if(v==i) continue;
				f[i][v]=f[v][i]=t[i][j]+p.sc;
			}
		}
	}
	for(int K=1;K<=n;K++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][K]+f[K][j]);
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<f[i][j]<<' ';
		cout<<'\n';
	}*/
	int u,v;
	for(int i=1;i<=q;i++){
		cin>>u>>v;
		ll mn=1e18;
		for(auto p : G[u]){
			ll x=p.fs,wx=p.sc;
			for(auto pp : G[v]){
				ll y=pp.fs,wy=pp.sc;
				mn=min(mn,wx+wy+f[x][y]);
			}
		}
		cout<<mn+w[u]+w[v]<<'\n';
	}
	return 0;
}
