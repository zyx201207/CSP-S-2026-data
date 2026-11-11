#include <bits/stdc++.h>
using namespace std;
long long m,n,a[200005],vis[200005],mx;
void dfs(long long lev,long long sum)
{
	if(lev==m+1)
	{
		mx=max(mx,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		int temp=sum;
		vis[i]=1;
		if(sum==0) sum=a[i];
		else sum=sum&a[i];
		dfs(lev+1,sum);
		sum=temp;
		vis[i]=0;
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
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1) mx=a[i];
			else mx=mx&a[i];
		}
		cout<<mx<<endl;
		return 0;
	}
	if(n<=2000)
	{
		dfs(1,0);
		cout<<mx<<endl;	
	}
	else cout<<0<<endl;
	return 0;
} 
