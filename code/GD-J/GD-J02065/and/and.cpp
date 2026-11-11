#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[200005],m,sum,ans;
void dfs(int x)
{
	if(x>m)
	{
		sum=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		ans=ans&a[x];
		dfs(x+1);
		return;
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
	for(int i=1;i<=n;i++)
	{
		ans=a[i];
		dfs(1);
	}
	cout<<sum;
	return 0;
	return 0;
}
