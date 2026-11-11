#include<bits/stdc++.h>
using namespace std;
int an(int a,int b)
{ 
	if(a==b) return a;
	int ret=0;
	if(a>b) swap(a,b);
	string sa="",sb="";
	while(a>0)
	{
		sa+=(a%2+'0');
		a/=2;
	} 
	while(b>0)
	{
		sb+=(b%2+'0');
		b/=2;  
	}  
	for(int i=sa.size()-1;i>=0;i--)
	{  
		if(sa[i]=='1'&&sb[i]=='1') 
		{
			ret=ret*2+1;
		}
		else
		{
			ret*=2; 
		} 
	} 
	return ret;
}
int n,m;
int a[200005];
int maxn=-1e9;
int dis[200005];
void dfs(int i,int cnt)
{
	if(cnt==m)
	{
		int ret=dis[1];
		for(int i=2;i<=m;i++)
		{
			ret=an(ret,dis[i]);
		}
		maxn=max(maxn,ret);
		return ;
	}
	for(int j=i+1;j<=n-(m-cnt)+1;j++)
	{
		dis[cnt+1]=a[j];
		dfs(j,cnt+1);
		dis[cnt+1]=0;
	}
}
int main()
{ 

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	} 
	if(n==m)  
	{ 
		maxn=a[1];
		for(int i=2;i<=n;i++)
		{
			maxn=an(maxn,a[i]);
		}
		cout<<maxn;
		return 0; 
	}
	if(m==n-1)
	{
		int ans;
		for(int i=1;i<=n;i++)
		{
			if(i!=1) ans=a[1];
			else ans=a[2]; 
			for(int j=2;j<=n;j++)
			{
				if(i!=j)
				{
					ans=an(ans,a[j]);
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	dfs(0,0); 
	cout<<maxn;
	return 0;
}
