#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[500005],k[505],f[505][505];
vector<int>a[505],t[505];
vector<array<int,2>>ve[500005];
signed main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i],a[i].resize(k[i]),t[i].resize(k[i]);
		for(int j=0;j<k[i];j++)cin>>a[i][j]>>t[i][j],ve[a[i][j]].push_back({i,t[i][j]});
	}
	memset(f,0x3f,sizeof f);for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=n;i++)for(int j=0;j<k[i];j++)for(auto v:ve[a[i][j]])if(v[0]^i)f[i][v[0]]=min(f[i][v[0]],t[i][j]+v[1]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		cin>>x>>y;int ans=1e18;
		for(auto i:ve[x])for(auto j:ve[y])ans=min(ans,f[i[0]][j[0]]+i[1]+j[1]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
