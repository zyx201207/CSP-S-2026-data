#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long n,m,ans;
void dfs(long long last,long long cnt,long long sum_and)
{
	if (cnt==m)
	{
		ans=max(ans,sum_and);
		return;
	}
	for (int i=last+1;i<=n;i++)
	{
		if (sum_and==0)
		{
			dfs(i,cnt+1,a[i]);
		}
		else
		{
			dfs(i,cnt+1,sum_and&a[i]);
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i;
	cin >> n >> m;
	for (i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (n<=2000)
	{
		dfs(0,0,0);
		cout << ans;
	}
	else
	{
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	}
	return 0;
}
