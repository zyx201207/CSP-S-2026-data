#include<bits/stdc++.h>

using namespace std;
int n,m,a[2005],ans;
void dfs(int step,int set,int as)
{
	if(step >= m)
	{
		ans = max(ans,as);
		return ;
	}
	if(ans && !as)
	{
		return ;
	}
	for (int i = set + 1;i < n;i++)
	{
		dfs(step + 1,i,as & a[i]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(n > 2000)
	{
		int q;
		int as;
		cin >> q;
		as = q;
		for (int i = 1;i < n;i++)
		{
			cin >> q;
			as &= q;
			ans = max(q,ans);
		}
		if(m == n)cout << as;
		else cout << ans;
	}
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0;i < n - m;i++)
	{
		dfs(1,i,a[i]);
	}
	cout << ans;
	return 0;
}
