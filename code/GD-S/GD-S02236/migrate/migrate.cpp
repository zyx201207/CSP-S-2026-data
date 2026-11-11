#include <iostream>
using namespace std;
#define ll long long
const int N = 2e6+5;
ll x[N];
int n;
ll d;
int cnt;
int minl = 1e9;
void dfs1(int p, int tar, int l)
{
	if (p == tar)
	{
		minl = min(l,minl);
		return ;
	}
	for (int i = p+1; i <= tar; i++)
	{
		if (x[i]-x[p] <= d) dfs1(i,tar,l+1);
	}
}
void dfs2(int p, int tar, int l)
{
	if (p == tar)
	{
		if (l == minl) cnt++;
		return ;
	}
	for (int i = p+1; i <= tar; i++)
	{
		if (x[i]-x[p] <= d) dfs2(i,tar,l+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				minl = 1e9;
				dfs1(i,j,0);
				cnt = 0;
				dfs2(i,j,0);
				if (cnt == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

