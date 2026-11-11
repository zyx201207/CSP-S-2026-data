#include<bits/stdc++.h>
using namespace std;

int x[300000];
int n,m;
int dfs(int s,int g)
{
	if(g==n)
	{
		return x[s];
	}
	for(int i=s+1;i<=n-g+1;i++)
	{
		return (dfs(i,g+1)&x[s]);
	}
}

int main(){
	freopen("and2.in","r",stdin);
	freopen("and2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==m)
	{
		int ans=x[1];
		for(int i=2;i<=n;i++)
		{
			ans&=x[i];
		}
		cout<<ans;
	}
	else if(m==1)
	{
		int ans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,x[i]);
	 	} 
		cout<<ans; 
	}
	else if(m==2)
	{
		int ans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(x[i]&x[j]));
			}
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		int ans=dfs(1,1);
		cout<<ans;
	}
	else if(m==n-1)
	{
		int ans=x[1];
		for(int i=2;i<=n;i++)
		{
			ans&=x[i];
		}
		
	}
	return 0;
}
