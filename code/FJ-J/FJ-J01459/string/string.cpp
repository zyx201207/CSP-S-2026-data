#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

struct S
{
	int num;
	char c;
	void read()
	{
		cin >> num >> c;
	}
}a[N + 5];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) a[i].read();
	
	int l = 1, r = n;
	long long ans = 0;
	while (l <= r)
	{
		if (l == r) l ++;
		
		int minn = min(a[l].num, a[r].num);
		
		if (a[l].c == a[r].c)
		{
			a[l].num -= minn;
			a[r].num -= minn;
			if (a[l].num == 0) l ++;
			if (a[r].num == 0) r --;
		}
		else
		{
			ans += minn;
			a[l].num -= minn;
			a[r].num -= minn;
			if (a[l].num == 0) l ++;
			if (a[r].num == 0) r --;
		}
	}
	
	cout << ans;
	
	return 0;
}
