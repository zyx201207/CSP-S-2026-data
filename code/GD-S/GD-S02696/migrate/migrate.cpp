#include <bits/stdc++.h>
using namespace std;
int n,m,c,t;
int a[2000005],f[200005];
bool vis[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int Q=1;Q<=t;Q++)
	{
		memset(a,0,sizeof(a));
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(f,0,sizeof(f));
			vis[i]=1;
			f[i]=1;
			for(int j=i;j<=n;j++)
			{
				if(vis[j-1])f[j]++;
				if(vis[j])
				{
					
					for(int k=n;k>=j+2;k--)
					{
						if(abs(a[k]-a[j])<=m)
						{
							if(vis[k])continue;
							vis[k]=1;
							f[k]++;
							break;
						}
						
					}
				}
				if(!vis[j])
				{
					
					for(int k=j-1;k>=i;k--)
					{
						if(abs(a[j]-a[k])<=m)
						{
							if(vis[k])continue;
							
							f[j]++;
						}
						
					}
				}
			}
			
			for(int j=i;j<=n;j++)
			{
				if(f[j]==2)ans++;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
