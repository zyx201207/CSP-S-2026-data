#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 5e5 + 5;

int n;
LL m, a[N];

int idx;
struct Node
{
	LL v;
	int t;
}b[N];

int res;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	idx ++ ;
	b[idx].v = a[1], b[idx].t = 1;
	for (int i = 2; i <= n; i ++ )
		if (a[i] == a[i - 1])
			b[idx].t ++ ;
		else
		{
			idx ++ ;
			b[idx].v = a[i], b[idx].t = 1;
		}
	
	int l = 1, cnt = 0;
	LL s = 0;
	for (int i = 1; i <= idx; i ++ )
	{
		cnt += b[i - 1].t;
		s = s + cnt * (b[i].v - b[i - 1].v);
		
		while (l < i && s > m)
		{
			if (s - m > (b[i].v - b[l].v) * b[l].t)
			{
				cnt -= b[l].t;
				s -= (b[i].v - b[l].v) * b[l].t;
				b[l].t = 0;
				l ++ ;
			}
			else
			{
				LL x = (s - m + (b[i].v - b[l].v) - 1) / (b[i].v - b[l].v);
				cnt -= x;
				s -= x * (b[i].v - b[l].v);
				b[l].t -= x;
				break;
			}
		}
		if (s >= 0)
			res = max(res, cnt + b[i].t);
	}
	
	cout << res << '\n';
	
	return 0;
}

