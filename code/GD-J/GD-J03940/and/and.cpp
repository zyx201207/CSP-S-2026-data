#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dfs(int i,int rest,int sum)
{
	if (i>n)	return sum;
	if (rest<=0)	return sum;
	int rt=0;
	for (int j = i+1;j+rest<=n+1;j++)
	{
		if (rest == m)	rt = max(rt,dfs(j,rest-1,a[j]));
		else rt = max(rt,dfs(j,rest-1,(sum&a[j])));
	}
	return rt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i<=n;i++)	cin >> a[i];	
	if (n == m)
	{
		int ans = a[1];
		for (int i = 2;i<=n;i++)
			ans&=a[i];
		cout << ans;
	}
	else if (m == 2)
	{
		int ans = 0;
		for (int i = 1;i<=n;i++)
		{
			for (int j = i+1;j<=n;j++)
				ans = max(ans,a[i]&a[j]);
		}
		cout << ans;
	}
	else if (m == 1||n == 2*1e5)
	{
		int ans = a[1];
		sort(a+1,a+n+1);
		for (int i = n;i>=n-m+1;i--)
			ans&=a[i];
		cout << ans;
	}
	else if (n<=20)	cout << dfs(0,m,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
