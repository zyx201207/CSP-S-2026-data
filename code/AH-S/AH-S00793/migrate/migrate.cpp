#include<bits/stdc++.h>
using namespace std;
const int M = 2e6 + 5;
int c , T;
long long n;
long long d , ans;
long long x[M];
void solve1()
{
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++)
		cin >> x[i];
	long long dist = x[2] - x[1];
	if(d < dist)
	{
		cout << 0 << "\n";
		return;
	}
	long long qaq = d / dist;
	if(qaq == 1)
	{
		cout << 0 << "\n";
		return;
	}
	ans = 0;
	for(long long i = 2 ; i <= qaq ; i++)
	{
		if((i - 1) * n - 3 * i * (i - 1) / 2 >= 0)
			ans += (i - 1) * n - 3 * i * (i - 1) / 2;
	}
	cout << ans << "\n";
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		if(c == 11 || c == 12)
			solve1();
	}
	return 0;
}
