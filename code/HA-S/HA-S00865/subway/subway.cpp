#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
const int N=555,M=5e5+114;
struct ed{
	int t;ll v;
};
vector<ed> dts[M];
ll dis[N][N];
ll val[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=2e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;ll v;
			cin>>a>>v;
			for(ed e:dts[a]){
				dis[e.t][i]=dis[i][e.t]=min(dis[e.t][i],e.v+v);
			}
			dts[a].push_back({i,v});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		ll ans=2e18;
		for(ed a:dts[x]){
			for(ed b:dts[y]){
				ans=min(ans,a.v+b.v+dis[a.t][b.t]);
			}
		}
		cout<<ans+val[x]+val[y]<<'\n';
	}
	return 0;
}

