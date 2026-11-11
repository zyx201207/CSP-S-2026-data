#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		vector<int>x(n+1,0);
		for(int i=1;i<=n;i++)
			cin>>x[i];
		int g[n+1][n+1],h[n+1][n+1][n+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)	
				for(int k=1;k<=n;k++)
					h[i][j][k]=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[i]+d>=x[j])
					g[i][j]=1;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=i;k<=j;k++)	
				{
					if(g[i][j]>g[i][k]+g[k][j])
						g[i][j]=g[i][k]+g[k][j];
					h[i][j][g[i][j]]++;
				}	
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				cout<<i<<"->"<<j<<":"<<g[i][j]<<"\n";
		int ans=0;	
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(h[i][j][g[i][j]]==2)
					ans++;
		cout<<ans<<'\n';
	}
}
