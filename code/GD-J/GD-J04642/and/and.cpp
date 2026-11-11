#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m,a[N],ans;
bool flag = 1,vis[N];
bool cmp(int x,int y)
{
	return x > y;
}
void dfs(int step,int sum)
{
	if(step > m)
	{
		ans = max(ans,sum);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			dfs(step + 1,(sum & a[i]));
			vis[i] = 0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int maxn = -1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		double lq1 = log2(a[i] + 1);
		int lq2 = lq1;
		if(double(lq2) != lq1)
			flag = 0;
	}
	if(m == 1)
	{
		cout << maxn << endl;
		return 0;
	}
	else if(m == n)
	{
		int ans = a[1];
		for(int i = 2;i <= n;i++)
		{
			ans = (ans & a[i]);
		}
		cout << ans << endl;
		return 0;
	}
	else if(m == 2)
	{
		int maxn2 = -1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j)
					continue;
				maxn2 = max(maxn2,(a[i] & a[j]));
			}
		}
		cout << maxn2 << endl;
		return 0;
	}
	else if(flag)
	{
		sort(a + 1,a + n + 1,cmp);
		cout << a[m] << endl;
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			vis[i] = 1;
			dfs(2,a[i]);
			vis[i] = 0;
		}
		cout << ans << endl; 
	}
	return 0;
}
