#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,m,n,d,q,cl[600000];
ll v[600000],cv[600000][25],f[550][550],ct[600000][25],ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  cin>>v[i];
	int x,y;
	ll z;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
	  cin>>x;
	  for(int j=1;j<=x;j++)
	  {
		cin>>y>>z;
		cl[y]++;cv[y][cl[y]]=z;
		ct[y][cl[y]]=i;
		for(int k=1;k<cl[y];k++)
		  f[i][ct[y][k]]=f[ct[y][k]][i]=min(f[ct[y][k]][i],cv[y][k]+z);
	  }
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	for(int i=1;i<=n;i++)
	  f[i][i]=0;
	while(q)
	{
		q--;
		cin>>x>>y;
		ans=f[0][0];
		for(int i=1;i<=cl[x];i++)
		  for(int j=1;j<=cl[y];j++)
		  {
		  	z=f[ct[x][i]][ct[y][j]]+v[x]+v[y]+cv[x][i]+cv[y][j];
		  	ans=min(z,ans);
		  }
		cout<<ans<<endl;
	}
	return 0;
}

