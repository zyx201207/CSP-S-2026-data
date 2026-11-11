#include <iostream>
using namespace std;
int n,m,a[200005],ans;
void dfs(int i,int c,int s)
{
	if(i>n)
	{
		if(c>=m)
		{
			ans=max(ans,s);
		}
		return;
	}
	if(c>=m)
	{
		ans=max(ans,s);
		return;
	}
	if(c==0)
	{
		dfs(i+1,c+1,a[i]);
	}
	else
	{
		dfs(i+1,c+1,a[i]&s);
	}
	dfs(i+1,c,s);
}
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout << ans;
}
void solve2()
{
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ans&=a[i];
	}
	cout << ans;
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout << ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n<=20)
	{
		dfs(1,0,0);
		cout << ans;
	}
	else
	{
		if(m==1)
		{
			solve1();
		}
		else if(m==n)
		{
			solve2();
		}
		else
		{
			solve3();
		}
	}
	return 0;
}
