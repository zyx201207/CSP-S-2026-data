#include<bits/stdc++.h>
#define int long long
using namespace std;

int c,n,m,d,q,f[550][550],t[550][550],w[550],a[550][550],tot[505050];
//vector<pair<int,int>>v[505050];

//caonimade最后10分钟想到了tmdlgb的为啥啊操傻逼吧我 

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	memset(f,0x3f,sizeof f);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)cin>>a[i][j]>>t[i][j];
//		,v[a[i][j]][++tot[a[i][j]]]={i,t[i][j]}
		for(int j=1;j<=k;j++)for(int l=1;l<=k;l++)if(j!=l)f[a[i][j]][a[i][l]]=min(f[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
	}
	for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)if(i!=k&&k!=j&&j!=i)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;cin>>x>>y;
		cout<<w[x]+w[y]+f[x][y]<<"\n";
	}
	
	return 0;
}
