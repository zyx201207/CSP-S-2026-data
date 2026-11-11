#include <iostream>
#include <algorithm>
#define i64 long long
#define ull unsigned long long
#define AC return 0;
#define int i64
using namespace std;

inline void initbegin ()
{
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	return ;
}

const int N = 200001, M = 5001;
const int inf = 0x3f3f3f3f, mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

i64 ans = 0;
int n, lp, ln, rp, rn, sum = 0;
int ge[N];

struct S {
    int a;
    int lw, rw;
    char c;
} s[N], k[N];

void baoli ();

int mian ()
{
    cin >> n;
    lp = ln = 0;
    rp = rn = n;
    for (register int i = 1; i < n + 1; ++i)
    {
        cin >> s[i].a >> s[i].c;
        s[i].lw = sum;
        sum += s[i].a;
        s[i].rw = sum;
    }
    if (sum <= 1e8)
    {
        baoli ();
        AC
    }
    int su = 0;
    for (register int i = 1; i < n; ++i)
    {
        su += s[i].a;
        ge[i] = su;
        // cout << su << " ";
    }
    // cout << "\n";
    su = 0;
    for (register int i = n; i > 1; --i)
    {
        su += s[i].a;
        ge[n - i + n] = su;
        // cout << su << " ";
    }
    // cout << "\n";
    int len = 2 * n - 2;
    sort (ge + 1, ge + len + 1);
    ge[len + 1] = sum;
    // for (int i = 1; i <= len; i++)
    // {
    //     cout << ge[i] << " ";
    // }
    // cout << "\n";
    for (register int i = 1; i < len + 2; ++i)
    {
        k[i].a = ge[i] - ge[i - 1];
    }
    for (register int i = 1; i < len + 2; ++i)
    {
        k[i].c = '0';
        if (i < len / 4)
        {
            for (register int j = 1; j < n + 1; ++j)
            {
                if (ge[i] >= s[j].lw && ge[i] <= s[j].rw)
                {
                    k[i].c = s[j].c;
                    break;
                }
            }
        }
        else if (i < len / 2)
        {
            for (register int j = n / 4; j < n + 1; ++j)
            {
                if (ge[i] >= s[j].lw && ge[i] <= s[j].rw)
                {
                    k[i].c = s[j].c;
                    break;
                }
            }
        }
        else if (i < len * 3 / 4)
        {
            for (register int j = n / 2; j < n + 1; ++j)
            {
                if (ge[i] >= s[j].lw && ge[i] <= s[j].rw)
                {
                    k[i].c = s[j].c;
                    break;
                }
            }
        }
        else
        {
            for (register int j = n * 3 / 4; j < n; ++j)
            {
                if (ge[i] >= s[j].lw && ge[i] <= s[j].rw)
                {
                    k[i].c = s[j].c;
                    break;
                }
            }
        }
        if (k[i].c == '0')
        {
            for (register int j = 1; j < n + 1; ++j)
            {
                if (ge[i] >= s[j].lw && ge[i] <= s[j].rw)
                {
                    k[i].c = s[j].c;
                    break;
                }
            }
        }
    }
    // for (int i = 1; i <= len + 1; i++)
    // {
    //     cout << k[i].a << " " << k[i].c << "\n";
    // }
    for (register int l = 1, r = len + 1; l < r + 1; ++l, --r)
    {
        if (k[l].c != k[r].c)
        {
            ans += k[l].a;
        }
    }
    cout << ans;
	AC
}

/*
5
3 a
6 b
5 c
2 d
5 e

aaa bb bb bb ccc cc dd ee eee



sum = 21
3 9 14 16
5 7 12 18
3 5 7 9 12 14 16 18
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

void baoli ()
{
    string ss;
    for (register int i = 1; i < n + 1; ++i)
    {
        for (register int j = 0; j < s[i].a; ++j)
        {
            ss += s[i].c;
        }
    }
    for (register int i = 0, j = ss.size () - 1; i < j; ++i, --j)
    {
        ans += (ss[i] != ss[j]);
    }
    cout << ans;
}