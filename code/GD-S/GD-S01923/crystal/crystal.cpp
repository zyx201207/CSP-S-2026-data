#include <bits/stdc++.h>
using namespace std;

const int N = 6 * 1e5;
long long n, a[N], m, ans = 0;
unsigned long long sum = 0;
bool ns = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if((a[i - 1] > a[i] && a[i - 1] < a[i - 2]) || (a[i - 1] < a[i] && a[i - 1] > a[i - 2]))
		{
			ns = false;
		}
		if(a[i - 1] != a[i])
		{
			ns == false;
		}
	}
	if(ns == false)
	{
		sort(a + 1, a + n + 1);
	}
	queue<long long> q;
	q.push(a[1]);
	for(int i = 2; i <= n; i ++)
	{
		sum += (a[i] - a[i - 1]) * q.size();
		q.push(a[i]);
		while(sum > m)
		{
			sum -= a[i] - q.front();
			q.pop();
			
		}
		long long sz = q.size();
		ans = max(ans, sz);
	}
	cout << ans << "\n";
}
