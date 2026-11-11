#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2e5 + 10; 

int t;
long long ans;
pair<int, char> seg[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	for (int i = 1; i <= t; i++) cin >> seg[i].first >> seg[i].second;
	
	int p1 = 1, p2 = t;
	while (p1 < p2)
	{
		int smaller = min(seg[p1].first, seg[p2].first);
		if (seg[p1].second != seg[p2].second) ans += smaller;
		if (seg[p1].first > seg[p2].first)
		{
			seg[p1].first -= smaller;
			p2--;
		}
		else if (seg[p1].first < seg[p2].first)
		{
			seg[p2].first -= smaller;
			p1++;
		}
		else if (seg[p1].first == seg[p2].first)
		{
			p1++;
			p2--;
		}
	}
	
	cout << ans << endl;
	return 0;
}
