#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=510;
const int M=505000;
ll c,n,m,d,q,w[M],f[N][N];
map<pair<int,int>,int> mp;
vector<int> gl[M];
vector<pair<int,int>> g[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=1e18;
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,a,t;j<=k;j++) scanf("%d%d",&a,&t),gl[a].push_back(i),g[a+n].push_back({i,t}),g[i].push_back({a+n,t}),mp[{a,i}]=t;
	}
	for(int i=1;i<=n;i++){
		for(auto y:g[i]){
			for(auto z:g[y.first]){
				f[i][z.first]=min(f[i][z.first],(ll)y.second+(ll)z.second);
				f[z.first][i]=min(f[z.first][i],(ll)y.second+(ll)z.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int x,y;q;--q){
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(auto u:gl[x]){
			for(auto v:gl[y]){
				ans=min(ans,f[u][v]+mp[{x,u}]+mp[{y,v}]);
			}
		}printf("%lld\n",ans+w[x]+w[y]);
	}
	rt 0;
}
