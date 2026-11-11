#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int w = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n,m,a[w],ans,s,dfsss[w];
void dfs(int x,int fa,int last)
{
	if (x < 0 || n - last)
		return;
	for (int i = last;i <= n;i++)
	{
		if (a[i] < (1 << x))
		{
			if (i < m)
				dfs(x - 2,fa,i);
			ans = max(ans,fa + (1 << x));
			dfs(x - 1,fa + (1 << x),i);
		}
	}
	cout << a[n];
	exit(0);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1,greater<int>());
	int maxx = floor(log2(a[1])) + 1,sum;
	s = 1;
	while (sum < m)
	{
		maxx--;
		sum = 0;
		for (int i = s;i <= n;i++)
		{
			if (a[i] < (1 << maxx))
			{
				s = i;
				break;
			}
			sum++;
		}
	}
	n = s - 1;
	dfs(maxx - 1,(1 << maxx),1);
	cout << ans;
	return 0;
}
//31 15 7 6 5 5 ans = 12
