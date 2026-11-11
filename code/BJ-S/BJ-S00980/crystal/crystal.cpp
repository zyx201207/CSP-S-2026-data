#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m;
long long a[N], ans = 0, cnt = 0;
priority_queue<long long> pq;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		int tmp = m;
		cnt = 0;
		
		for (int j = 1; j <= n; j++)
		{
			if (a[i] <= a[j])
			{
				cnt += (a[i] == a[j]);
				continue;
			}
			
			int d = a[i] - a[j];
			pq.push(d);
			tmp -= d, cnt++;
			
			if (tmp < 0)
			{
				tmp += pq.top();
				pq.pop();
				cnt--;
			}
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
	
	return 0;
}