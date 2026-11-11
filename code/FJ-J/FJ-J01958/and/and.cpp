#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int a[100010];
bool st[100010];
int n,m;
int ant=0;
void dfs(int x,int sum)
{
	if(x>n||sum==m)
	{
		if(sum==m)
		{
			int d=0;
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(st[i]==1&&d==0)
				{
					ans=a[i];
					d++;
				}
				else if(st[i]==1) 
				{
					ans=ans&a[i]; 
				}
			}
			ant=max(ant,ans);
		}
		return ;
	}
	dfs(x+1,sum);
	st[x]=1;
	dfs(x+1,sum+1);
	st[x]=0;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		int ma=0;
		for(int i=1;i<=n;i++)
		{
			ma=max(a[i],ma);
		}
		cout<<ma;
		return 0;
	}
	else if(m==n)
	{
		int ss=0;
		for(int i=1;i<=n;i++)
		{
			if(ss==0)
			{
				ss=a[i];
			}
			else 
			{
				ss=ss&a[i];
			}
		}
		cout<<ss;
		return 0;
	}
	else if(m==n-1)
	{
		int ss=0;
		for(int i=1;i<=n;i++)
		{
			int ana=0;
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					if(ana==0)
					{
						ana=a[j];
					}
					else
					{
						ana=ana&a[j];
					}
				}
			}
			ss=max(ss,ana);
		}
		cout<<ss;
		return 0;
	}
	dfs(1,0);
	cout<<ant;
	return 0;
} 
