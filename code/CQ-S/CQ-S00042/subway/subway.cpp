#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=500+10;
	const int maxm=5e5+10;
	const ll INFL=1e18;
	int cid,n,m,limd,q;
	int a[maxm];
	vector<pair<int,int>>vt[maxm];
	ll f[maxn][maxn];
	int main(){
		cin>>cid>>n>>m>>limd>>q;
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1,x,t;j<=k;j++){
				cin>>x>>t;
				vt[x].push_back({i,t});
			}
		}
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int i=1;i<=m;i++){
			for(pair<int,int>e1:vt[i])for(pair<int,int>e2:vt[i]){
				f[e1.first][e2.first]=f[e2.first][e1.first]=min(f[e2.first][e1.first],(ll)e1.second+e2.second);
			}
		}
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		while(q--){
			int x,y;
			cin>>x>>y;
			ll ans=INFL;
			for(pair<int,int>ex:vt[x])for(pair<int,int>ey:vt[y])ans=min(ans,f[ex.first][ey.first]+ex.second+ey.second);
			ans+=a[x]+a[y];
			cout<<ans<<'\n';
		}

		return 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}

