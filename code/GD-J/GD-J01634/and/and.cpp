#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n , m , maxi = -1 , all , now , ans , cnt;
int a[N];
int st[N];
bool use[N] = {false};

void dfs()
{
	if(cnt >= m)
	{
		now = st[0];
		for (int i = 0 ; i < cnt ; i ++)
		{
			now &= st[i];
		}
		ans = max(ans , now);
		return;
	}
	for (int i = 0 ; i < n ; i ++)
	{
		if (use[i])
		{
			continue;
		}
		st[cnt] = a[i];
		cnt ++;
		use[i] = true;
		dfs();
		use[i] = false;
		cnt --;
	}
}

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> a[i];
		maxi = max(a[i] , maxi);
		if (i == 0)
		{
			all = a[0];
		}
		else
		{
			all &= a[i];
		}
	}
	if (m == 1)
	{
		cout << maxi << '\n';
		return 0;
	}
	if (m == n)
	{
		cout << all << '\n';
		return 0;
	}
	dfs();
	cout << ans << '\n';
	
	return 0;
}
