#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000010];
bool vis[1010];
int f[1010];
int ans[11][11];
int mn[11][11];
void dfs(int start,int end,int u,int dis)
{
//	cout<<start<<' '<<end<<' '<<dis<<endl;
	if(u==end)
	{
//		cout<<"AAA"<<start<<' '<<end<<' '<<u<<' '<<dis<<endl;
		if(mn[start][end]==dis)ans[start][end]++;
		else if(mn[start][end]>dis)ans[start][end]=1,mn[start][end]=dis;
		return ;
	}
	for(int i=u+1;a[i]-a[u]<=d&&i<=end;i++)
	{
//		cout<<i<<' '<<a[i]<<' '<<a[u]<<"<---- "<<endl;
		dfs(start,end,i,dis+1);
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11&&c<=12)
	{
		int ans=0;
		while(t--)
		{
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				
			}
			int dis=a[2]-a[1];
			int num=d/dis;
			for(int i=1;i<=n;i++)
			{
				ans+=max(min((i+2*num-1),n)-(i+num+1)+1,0);
	//			cout<<min((i+2*num-1),n)<<' '<<(i+num+1)<<endl;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		while(t--)
		{
			memset(mn,0x3f3f3f3f,sizeof mn);
			cin>>n>>d;
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				f[i]=f[i-1]+a[i];
			}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
				{
					dfs(i,j,i,0);
				}
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					if(ans[i][j]==2)sum++;
			cout<<sum<<endl;
		}
	}
	return 0;
}   
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/