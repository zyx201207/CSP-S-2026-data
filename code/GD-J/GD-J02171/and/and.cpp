#include<bits/stdc++.h>

using namespace std;
int lst = 0, n, m, cnt[35];
long long ans, maxx = -1;
void cal(int x)
{
	int p = 0;
	while(x)
	{
		cnt[p++] += x%2;
		x /= 2;
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++)
	{
		cin >> x;
		maxx = max(maxx, 1ll*x);
		cal(x);
	}
	if(m==1)
	{
		ans = maxx;
	}
	else
	{
		for(int i = 31; i >= 0; i--)
		{
			if(cnt[i]>=m&&cnt[i]>=lst)
			{
				lst = cnt[i];
				ans += 1<<i;
			}
		}
	}
	cout << ans;
	
	return 0;
}
