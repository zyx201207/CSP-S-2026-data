#include<bits/stdc++.h>
using namespace std;
long long int a[1010101];
vector<long long int> e[1010101];
long long int vis[1010101];
bool t=false,f=false,uu=false;
void dfs1(long long int s,long long int t)
{
	if(s==t)
	{
		t=true;
		return ;
	}
	vis[s]=1;
	for(auto i:e[s])
	{
		if(vis[i]==0)
		{
			dfs1(i,t);
		}
	}
}
void dfs2(long long int s,long long int t)
{
	if(s==t)
	{
		f=true;
		return ;
	}
	vis[s]=1;
	for(auto i:e[s])
	{
		if(vis[i]==0)
		{
			dfs2(i,t);
		}
	}
}
void dfs3(long long int s,long long int t)
{
	if(s==t)
	{
		uu=true;
		return ;
	}
	vis[s]=1;
	for(auto i:e[s])
	{
		if(vis[i]==0)
		{
			dfs3(i,t);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		long long int n,d;
		cin>>n>>d;
		for(long long int i=1;i<=n;i++)
		{
			cin>>a[i];
		} 
		for(long long int i=1;i<=n;i++)
		{
			for(long long int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					e[i].push_back(j);
				}
			}
		}
		dfs1(1,n);
		vis[1]=0;
		vis[n]=0;
		dfs2(1,n);
		vis[1]=0;
		vis[n]=0;
		dfs3(1,n);
		long long int sum=0;
		if(t==true) sum++;
		if(f==true) sum++;
		if(uu==true) sum++;
		if(sum==2)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
}
