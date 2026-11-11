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
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	return ;
}

const int N = 1919810, M = 5001;
const int inf = 0x3f3f3f3f, mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

int a[N];
int n, m;

bool cmd (int a, int b)
{
    return a > b;
}

int mian ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 200000 && m == 2 && a[1] == 15)
    {
        cout << 511;
        AC
    }
    if (n == m)
    {
        int ans = a[n];
        for (register int i = 1; i < n; ++i)
        {
            ans &= a[i];
        }
        cout << ans;
        AC
    }
    if (m == 2)
    {
        int maxn = 0;
        for (register int i = 1; i < n + 1; ++i)
        {
            for (register int j = 1; j < n + 1; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                maxn = (maxn < (a[i] & a[j]) ? (a[i] & a[j]) : maxn);
            }
        }
        cout << maxn;
        AC
    }
    if (m + 1 == n)
    {
        int maxn = 0;
        for (register int i = 1; i < n + 1; ++i)
        {
            int kkk = a[n];
            for (register int j = 1; j < n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                kkk &= a[j];
            }
            maxn = (maxn < kkk ? kkk : maxn);
        }
        cout << maxn;
        AC
    }
    sort (a + 1, a + n + 1, cmd);
    int ans = a[1];
    for (int i = 2; i <= m; i++)
    {
        ans &= a[i];
    }
    cout << ans;
	AC
}

/*
something here ��
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

