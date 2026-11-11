#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
void dfs(int x,int p,int sum)
{
	if(x==m+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=p+1;i<=n;i++)
	{
		dfs(x+1,i,sum&a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<sum;
		return 0;
	}
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)dfs(2,i,a[i]);
		cout<<ans<<endl;return 0;
	}
	cout<<a[n-m+1];
	return 0;
} 
