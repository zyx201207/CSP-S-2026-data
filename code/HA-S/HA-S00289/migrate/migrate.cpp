#include<bits/stdc++.h>
using namespace std;
int c,t,sum=0,n,d,a[2000005],book[2000005],mmin=999999999,l;
void dfs2(int u,int v,int sum)
{
	if(u==v)
	{
		if(sum<mmin)
		{
			mmin=sum;
			return;
		}
	}
	for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=d;i++)
			{
			
				if((u+i==a[j]&&book[a[j]]==0)||(u-i==a[j]&&book[a[j]]==0))
				{
					book[a[j]]=1;
					dfs2(u+i,v,sum+i);
					book[a[j]]=0;
				}
			}
		} 
}
void dfs(int u ,int v,int x,int s)
{
	
	if(s==v)
	{
		
		if(x==mmin)
		{
			sum++;
			return;
            
		}
	}
	
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=d;i++)
			{
			
				if((s+i==a[j]&&book[a[j]]==0)||(s-i==a[j]&&book[a[j]]==0))
				{
					book[a[j]]=1;
					dfs(u,v,x+i,a[j]);
					book[a[j]]=0;
				}
			}
		} 
}
int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int y=1;y<=t;y++)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			mmin=999999999;
			for(int j=1;j<=n;j++)
			{
				for(int g=i+1;g<j;g++)
				{
					dfs2(i,j,0);
					dfs(i,j,0,i);
				}
				
			}
		}
		cout<<sum<<" ";
	}
	return 0;
} 
