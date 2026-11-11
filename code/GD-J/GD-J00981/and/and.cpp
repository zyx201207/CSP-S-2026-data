#include<bits/stdc++.h>
using namespace std;
int n,m,mx=INT_MIN;
int a[200005];
void dfs(int qs,int gs,int ans)
{
	if(ans<=mx) return;
	if(gs==m)
	{
		mx=ans;
		return;
	}
	for(int i=qs;i<=n-(m-gs)+1;i++)
	{
		dfs(i+1,gs+1,ans&a[i]);
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
		int ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	//选出m个数的按位与最大
	for(int i=1;i<=n-m+1;i++)
	{
		dfs(i+1,1,a[i]);
	}
	cout<<mx;
	return 0;
}
