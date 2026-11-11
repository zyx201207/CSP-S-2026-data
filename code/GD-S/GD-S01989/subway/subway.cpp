#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll= long long;
using ull= unsigned long long;
const int N=505,M=500005;
const ll inf=1e18;
int c,n,m,d,q,w[M];
vector<pair<int,int> > vec[M];
ll dis[N][N];
inline void mian() {
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) { // n^2
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++) { // \sum k
		int k;
		cin>>k;
		for(int a,t;k--;) {
			cin>>a>>t;
			vec[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++) { // \sum d^2
		for(auto& j: vec[i]) {
			for(auto& k: vec[i])
				if(j.se+k.se<dis[j.fi][k.fi])
					dis[j.fi][k.fi]=j.se+k.se;
		}
	}
	for(int k=1;k<=n;k++) // n^3
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int x,y;q--;) { // d^2q
		cin>>x>>y;
		ll ans=inf;
		for(auto& i: vec[x])
			for(auto& j: vec[y])
				ans=min(ans,i.se+j.se+dis[i.fi][j.fi]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int TwT=1;
//	cin>>TwT;
	while(TwT--) mian();
	return 0;
}

