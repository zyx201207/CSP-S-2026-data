#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m; 
int dfs(int d,int b,int c)
{
	//cout<<b<<endl;
	if(c==m)
	{
		//cout<<b<<endl; 
		return b;
	}
	int mx=0;
	for(int i=d+1;i<=n-m+c+1;i++)
	{
		int B=b&a[i];
		mx=max(mx,dfs(i,B,c+1)); 
	}
	return mx;
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
	if(n<=2000)
	{
		if(m==1)
		{
			sort(a+1,a+n+1);
			cout<<a[n];
		}
		else if(m==2)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						ans=max(ans,a[i]&a[j]);
					} 
				}
			}
			cout<<ans;
		}
		else if(m==n)
		{
			int ans=a[1];
			for(int i=2;i<=n;i++)
			{
				ans|=a[i];
			}
			cout<<ans;
		}
		else
		{
			cout<<dfs(0,0x7fffffff,0);
		}
	}
 } 
