#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505;
vector<pair<int,int>> ve[N];
int cid,n,m,d,q,w[N],dis[M][M];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr); 
	cin>>cid>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t; 
			cin>>a>>t;
			ve[a].emplace_back(i,t);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++) for(int j=0; j<ve[i].size(); j++) for(int k=j+1; k<ve[i].size(); k++) {
		auto [id1,t1]=ve[i][j];
		auto [id2,t2]=ve[i][k];
		dis[id1][id2]=dis[id2][id1]=min(dis[id1][id2],t1+t2);
	}
	for(int k=1; k<=n; k++) for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--) {
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto [id1,t1]:ve[x]) for(auto [id2,t2]:ve[y]) ans=min(ans,dis[id1][id2]+t1+t2);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//samples passed at 14:50
//ka chang?!
