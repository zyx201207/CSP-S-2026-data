#include<bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
int n, m, a[200010], s, h;
int dp[200010];
bool v[200010];
bool cmp(int a, int b)
{
	return a > b;
}
void dfs(int d, int k)
{
	if(h >= 9000000) return;
	if(d > m || k < s)
	{
		s = max(s, k);
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		h++;
		if(!v[i])
		{
			v[i] = 1;
			if(d == 1) dfs(d + 1, a[i]);
			else dfs(d + 1, k & a[i]);
			v[i] = 0; 
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	dfs(1, 0);
	cout<<s;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
