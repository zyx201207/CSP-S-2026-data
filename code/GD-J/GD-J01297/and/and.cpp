#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, arr[N], pos = -1;
bool cmp(int a, int b)
{
	for (int i = pos; i >= 0; i--)
	{
		int _a = (a >> i) & 1, _b = (b >> i) & 1;
		if (_a != _b) return _a > _b;		
	}
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 30; i >= 0; i--)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if ((arr[j] >> i) & 1) cnt ++;
		if (cnt >= m) {pos = i; break;}
	}
	if (pos == -1) {cout << 0; return 0;}
	sort(arr + 1, arr + n + 1, cmp);
	int cnt = INT_MAX;
	for (int i = 1; i <= m; i++) cnt = cnt & arr[i];
	cout << cnt;
	return 0;
 }
/*
X X XXX x x xxx
XX X XX xx x xx
X XX XXXX x xx xxxx
XX XX XX XXX xx xx xxxxx
XXX xxx
XXX X xxx x
XXX XXX xxx xxx
XXXXX xxxxx
XX xx XX xx XX xx XX xx
......

Only feels like 
nothing could be better when I'm with you,
when I'm with you.
Dancing all night
pray we're next together it's a breakthrough
it's a breakthrough.
	from Xterfusion - REDALiCE x T+PAZOLITE 
*/
