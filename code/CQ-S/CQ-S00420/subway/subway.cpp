#include<bits/stdc++.h>
using namespace std;
namespace MoonHalfx{
	#define int long long
	#define pii pair<int,int>
	const int N=505;
	const int M=5e5+5;
	int c,n,m,d,q;
	int w[M];
	int mp[N][N];
	int val[N][N]; 
	vector<pii>v[M];
	signed main(){
		cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int len;
			cin>>len;
			while(len--){
				int ax,by;
				cin>>ax>>by;
				v[ax].push_back({i,by});
			}
		}
		memset(mp,0x3f,sizeof mp);
		for(int i=1;i<=n;i++)mp[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int ix=0;ix<(int)v[i].size();ix++){
				for(int jx=0;jx<(int)v[i].size();jx++){
					int ax=v[i][ix].first,by=v[i][ix].second;
					int Ax=v[i][jx].first,By=v[i][jx].second;
					mp[ax][Ax]=min(mp[ax][Ax],by+By);
				}
			}
//			for(auto [ax,by]:v[i]){
//				for(auto [Ax,By]:v[i]){
//					mp[ax][Ax]=min(mp[ax][Ax],by+By);
//				}
//			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)val[i][j]=mp[i][j];
		for(int ij=1;ij<=n;ij++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					val[i][j]=min(val[i][j],val[i][ij]+val[ij][j]);
				}
			}
		}
		for(int i=1;i<=q;i++){
			int lf,rg;
			cin>>lf>>rg;
			int ans=0x3f3f3f3f3f3f3f3f;
			for(int ix=0;ix<(int)v[lf].size();ix++){
				for(int jx=0;jx<(int)v[rg].size();jx++){
					int ax=v[lf][ix].first,by=v[lf][ix].second;
					int Ax=v[rg][jx].first,By=v[rg][jx].second;
					ans=min(ans,by+By+val[ax][Ax]);
				}
			}
//			for(auto [ax,by]:v[lf]){
//				for(auto [Ax,By]:v[rg]){
//					ans=min(ans,by+By+val[ax][Ax]);
//				}
//			}
			cout<<ans+w[lf]+w[rg]<<"\n";
		}
		return 0;
	}
	#undef int
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	MoonHalfx::main();
	return 0;
}
/*
考虑如果能把线路之间建图
最多O(500^2)的边
对每个站台dij,时间O(n^2logn^2)
我记得有个O(n^3)的东西 
对于每个q,枚举去那个站台，时间O(qd^2)
如何见图，对于每个地铁站，有d^2个经过，有O(md^2)条边
对的对的 
*/
