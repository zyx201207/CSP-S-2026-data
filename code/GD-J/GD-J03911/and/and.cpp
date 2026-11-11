#include<bits/stdc++.h>
using namespace std;
long long n,k,a[220000],maxx,ans;
void dfs(int s,long long t,int jsq)
{
	if(jsq>k)
		return ;
	if(jsq==k)
	{
		maxx=max(maxx,t);
		return ;
	}	
	for(int i=s;i<=n;i++)
	{
		dfs(i+1,t&a[i],jsq+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2000||k==n-1)
	{
		for(int j=1;j<=n-k;j++)
		{
			maxx=0;
			dfs(j+1,a[j],1);
			ans=max(maxx,ans);
		}
		cout<<ans;
	}
	else
		cout<<n-k;
	return 0;
}
