#include<bits/stdc++.h>
using namespace std;
bool mapp[10000][10000]; 
int a[200000];
void build_map()
{
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=5005;i++)
			for(int j=1;j<=5005;j++)
				mapp[i][j]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]+a[j]<=d)mapp[i][j]=mapp[j][i]=1;
			}
		}
		build_map();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;i++)
			{
				int start=i,end=j;
			//	if(vis[i][j]==1)continue;
				//vis[i][j]=vis[j][i]=1;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}
