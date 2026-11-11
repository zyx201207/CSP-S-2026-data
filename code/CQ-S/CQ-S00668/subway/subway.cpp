#include<bits/stdc++.h>
using namespace std;
namespace ld{
	typedef long long ll;
	const int N=5e5+5;
	const ll INF=1e18;
	int CASE_BH,n,m,D,Q,a[N];ll f[505][505];
	vector<pair<int,int> >ed[N];
	
	int main(){
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		cin>>CASE_BH>>n>>m>>D>>Q;
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)f[i][j]=(i==j?0:INF);
		for(int i=1,k;i<=n;i++){
			cin>>k;
			for(int j=1;j<=k;j++){
				int p,w;
				cin>>p>>w;
				ed[p].push_back({i,w});
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<ed[i].size();j++)
				for(int k=j+1;k<ed[i].size();k++){
					auto[p1,w1]=ed[i][j];
					auto[p2,w2]=ed[i][k];
					f[p1][p2]=min(f[p1][p2],1ll*w1+w2);
					f[p2][p1]=min(f[p2][p1],1ll*w1+w2);
				}
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		for(int i=1,x,y;i<=Q;i++){
			cin>>x>>y;
			ll ans=INF;
			for(auto[p1,w1]:ed[x])
				for(auto[p2,w2]:ed[y]){
					ans=min(ans,w1+w2+f[p1][p2]+a[x]+a[y]);
				}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	ld::main();
	return 0;
}
