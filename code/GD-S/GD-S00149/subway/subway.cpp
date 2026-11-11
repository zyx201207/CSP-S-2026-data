#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=5e5+10,M=510;
int c,n,m,d,q;
vector<int>g[N];
unordered_map<int,int>v[N];
int f[M][M];
int b[N],w[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int y,z;
			cin>>y>>z;
			v[y][i]=z;
			g[y].emplace_back(i);
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
		for(int j:g[i])
			for(int k:g[i])
				if(j!=k)
					f[j][k]=f[k][j]=v[i][j]+v[i][k];
	for(int i=1;i<=m;i++)f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y];
		int mn=LONG_LONG_MAX;
		for(int i:g[x])
			for(int j:g[y])
				mn=min(mn,f[i][j]+v[x][i]+v[y][j]);
		ans+=mn;
		cout<<ans<<"\n";
	}
	return 0;
}
