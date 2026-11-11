#include <iostream>
#include <algorithm>
#include <cmath>
#define i64 long long
#define ull unsigned i64
#define AC return 0;
using namespace std;

void initbegin ()
{
    ios::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    return ;
}

const int N = 1919810, M = 5001, inf = 0x3f3f3f3f;
const int mod = 998244353;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

int a[N], ch[N], ans = 1, maxc, r, n;
i64 m;

bool check ();

void tejie ();

bool check2 (int ch);

void tejie2 (int ch);

void dfs (int c, int u, int sum, i64 r);

int mian ()
{
    cin >> n >> m;
    for (register int i = 1; i < n + 1; ++i)
    {
        cin >> a[i];
        if (i - 1)
        {
            ch[i] = a[i] - a[i - 1];
            maxc = (maxc < ch[i] ? ch[i] : maxc);
        }
    }
    if (check ())
    {
        tejie ();
        AC
    }
    if (check2 (a[2] - a[1]))
    {
        tejie2 (a[2] - a[1]);
        AC
    }
    sort (a + 1, a + n + 1);
    // cout << a[1] << " " << a[n] << "\n";
    if (n <= 5000)
    {
        for (register int i = 1; i < n + 1; ++i)
        {
            r = m;
            for (register int j = i; j < n + 1; ++j) // 77350ms
            {
                if (r < maxc || !(n - j))
                {
                    ans = (ans < j - i + 1 ? j - i + 1 : ans);
                }
                r -= (j - i + 1) * (a[j + 1] - a[j]);
                if (r < 0)
                {
                    break;
                }
            }
        }
    }
    else
    {
        for (register int i = 1; i < n + 1; ++i)
        {
            dfs (i, i, 1, m);
            // 55126ms
            // 为什么递归调用那么多次函数，55126ms，递推反而77350ms？？？？
            // 我很不理解
            // 还有这键盘，空格键坏了，要按好多下(╯▔皿▔)╯
            // 我右桌也是个人才，疯狂抖腿，把衣服挥舞的呼呼作响，还用水杯敲桌子……
            // 打扰完我了就睡觉……
            // 气死我了(╯▔皿▔)╯
        }
    } 
    cout << ans;
    AC
}

/*
something here……
*/

signed main ()
{
    initbegin ();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        mian ();
    }
    AC
}






bool check ()
{
    for (register int i = 1; i < n + 1; ++i)
    {
        if (a[i] != i)
        {
            AC
        }
    }
    return true;
}

void tejie ()
{
    i64 mm = sqrt (2 * m);
    // 1+……+mm=m;
    // ∴mm(mm+1)/2=m
    if (mm * (mm + 1) != 2 * m)
    {
        mm--;
    }
    cout << mm;
}

bool check2 (int ch)
{
    for (register int i = 1, shu = a[1]; i < n + 1; ++i, shu += ch)
    {
        if (a[i] != shu)
        {
            AC
        }
    }
    return true;
}

void tejie2 (int ch)
{
    int sum = 0;
    for (register int i = 1, j = ch; i < n; j += ch, i++)
    {
        sum += j;
        if (sum >= m)
        {
            cout << i + (sum == m);
            return ;
        }
    }
    cout << n;
}

void dfs (int c, int u, int sum, i64 r)
{
    if (u >= n)
    {
        // if(ans<sum)cout<<c<<" "<<sum<<"\n";
        ans = (ans < sum ? sum : ans);
        return ;
    }
    if (r < 1)
    {
        // if(ans<sum-(r<0))cout<<c<<" "<<sum-(r<0)<<"\n";
        ans = ((ans < sum - (r < 0)) ? sum - (r < 0) : ans);
        return ;
    }
    dfs (c, u + 1, sum + 1, r - sum * (a[u + 1] - a[u]));
}