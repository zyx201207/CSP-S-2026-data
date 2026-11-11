#include<bits/stdc++.h>
#define int long long
const int N=2e5+5;
using namespace std;
int n,m,ans,mmax,cnt;
int a[N];
void init()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		mmax=max(a[i],mmax);
	}
	cnt=a[1];
	for(int i=2; i<=n; i++)
		cnt=cnt&a[i];
}
void dfs(int k, int sum, int num)
{
	if(k > n)
	{
		if(num == m)
			ans=max(ans,sum);
		return ;
	}
	if(sum == 0)
	{
		dfs(k+1,a[k],num+1);
		dfs(k+1,sum,num);
	}
	else
	{
		dfs(k+1,sum&a[k],num+1);
		dfs(k+1,sum,num);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	init();
	if(n <= 20)
	{
		dfs(1,0,0);
		cout<<ans;
	}
	else if(m == 1)
		cout<<mmax;
	else if(m == 2)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i != j)
					ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m == n)
		cout<<cnt;
	else
	{
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n-1; i>=n-m+1; i--)
			ans=ans&a[i];
		cout<<ans;
	}
	return 0;
}
