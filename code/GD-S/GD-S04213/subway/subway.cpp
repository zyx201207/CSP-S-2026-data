#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
const ll inf=500000000000000005;

int n,m;
int q;
ll w[MAXN];

#define mp make_pair

vector<pair<int,ll> > gs[MAXN];
vector<pair<int,ll> > gr[505];

ll f[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c;cin>>c;
	cin>>n>>m;
	int d;cin>>d;
	cin>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		while(k--){
			int a;ll t;
			cin>>a>>t;
			gs[a].push_back(mp(i,t));
			gr[i].push_back(mp(a,t));
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) f[i][j]=0;
			else f[i][j]=inf;
		}
	}
	for(int i=1;i<=n;++i){
		for(auto x:gr[i]){
			for(auto k:gs[x.first]){
				int j=k.first;
				if(i==j) continue;
				f[i][j]=min(f[i][j],x.second+k.second);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
//			cerr<<i<<' '<<j<<' '<<f[i][j]<<'\n';
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(auto a:gs[x]){
			for(auto b:gs[y]){
				int i=a.first,j=b.first;
				ans=min(ans,f[i][j]+a.second+b.second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
} 
