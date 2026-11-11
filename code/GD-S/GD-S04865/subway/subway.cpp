#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,s,t,w[M],f[N][N];
vector<pair<int,int>> a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,t;j<=k;j++)
			cin>>u>>t,a[u].push_back({i,t});
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++) for(auto [x,tx] : a[i])
		for(auto [y,ty] : a[i]) if(x!=y) f[x][y]=tx+ty;
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(i!=j&&i!=k&&j!=k) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>s>>t;
		int ans=4e18;
		for(auto [x,tx] : a[s]) for(auto [y,ty] : a[t])
			ans=min(ans,w[s]+w[t]+tx+ty+f[x][y]);
		cout<<ans<<'\n';
	}
	return 0;
} 
