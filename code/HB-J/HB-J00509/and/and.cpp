#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define int long long
using namespace std;
int d[200005];
bool used[200005];
int ans = -1;
int n,m;
void dfs(int x,vector <int > a)
{
	if (x == m)
	{
		int wy = a[0];
		for (int i = 1;i < (int)a.size();i++)
			wy = wy & a[i];
		ans = max(ans,wy);
		return;
	}
	for (int i = 1;i <= n;i++)
	{
		if (used[i])
			continue;
		a.push_back(d[i]);
		used[i] = true;
		dfs(x + 1,a);
		a.pop_back();
		used[i] = false;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&d[i]);
	if (m == 1)
	{
		int maxv = -1;
		for (int i = 1;i <= n;i++)
			maxv = max(maxv,d[i]);
		printf("%lld\n",maxv);
	}
	else if (m == n)
	{
		int ans = d[1];
		for (int i = 2;i <= n;i++)
			ans = ans & d[i];
		printf("%lld\n",ans);
	}
	else if (m == 2)
	{
		int ans = -1;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j)
					ans = max(ans,d[i] & d[j]);
		printf("%lld\n",ans);
	}
	else
	{
		vector <int > aa;
		aa.clear();
		dfs(0,aa);
		printf("%lld\n",ans);
	}
	return 0;
}
