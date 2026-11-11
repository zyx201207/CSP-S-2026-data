#include <bits/stdc++.h>
#define i64 long long
#define ull unsigned long long
#define AC return 0;
using namespace std;

inline void initbegin ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	return ;
}

const int N = 1919810, M = 5001;
const int inf = 0x3f3f3f3f, mod = 998244353;

int a[N], ans[N];
int n, m;

map <int, int> mp, pm;

int mian ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (register int i = n; i > 0; i--)
    {
        if (pm[a[i]] == 0)
        {
            pm[a[i]] = i;
        }
    }
    int c = 0;
    for (register int i = 1; i < n + 1; ++i)
    {
        int cc[n + 1] = {};
        c = 0;
        for (register int j = i; j < n + 1; ++j)
        {
            cc[++c] = a[pm[a[j]]];
            j = pm[a[j]];
        }
        for (register int j = 1; j < c + 1; ++j)
        {
            ++ans[cc[j]];
        }
    }
    for (register int i = 1; i < m + 1; ++i)
    {
        cout << ans[i] << " ";
    }
	AC
}

/*
7 3
1 2 3 1 2 3 1
1
3
2
1

5 4
1 2 3 4 1
1
2341
341
41
1
5 1 2 3
6 2 3 4
*/

signed main ()
{
    initbegin ();
    int t = 1;
//	cin >> t;
    while (t--)
    {
		mian ();
	}
	AC
}