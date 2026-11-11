# include <bits/stdc++.h>
using namespace std;

long long n, d;
const long long MAXN = 2e6 + 7;
long long a[MAXN];
long long tot = 0;

void dfs(long long x, long long y, long long step, int xx, int yy)
{
    if (step == 0)
    {
        if (x == y)
        {
            tot ++;
//            cout << "xx, yy, tot : " << xx << " " << yy << " " << tot << endl;
            return ;
        }
        return ;
    }
    long long nx;
    for (long long i = x+1; i <= y; i++)
    {
        nx = i;
        step --;
//        cout << "x, nx, step: " << x << " " << nx << " " << step << endl;
        if (a[nx] - a[x] > d)
            break;

        if (a[nx] + step*d < a[y])
        {
            step ++;
            continue;
        }
//        cout << "x, nx, step (success): " << x << " " << nx << " " << step << endl;
        dfs(nx, y, step, xx, yy);
        step ++;
    }
}

bool check(long long x, long long y)
{
    long long step = 0;
    long long nx = x;
    while (true)
    {
        bool flag = false;
        for (long long i = y; i >= nx+1; i--)
        {
            if (a[i] - a[nx] <= d)
            {
                flag = true;
                step ++;
                nx = i;
                break;
            }
        }
        if (!flag)
            return false;
        if (nx >= y)
            break;
    }
//    cout << x << " " << y << " " << step << endl;
    tot = 0;
    if (step == 1)
        return false;
    dfs(x, y, step, x, y);
    if (tot == 2)
    {
        //cout << x << " " << y << endl;
        return true;
    }
    return false;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long c, t;
    cin >> c >> t;
    if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6)
    {
        while (t--)
        {
            long long cnt = 0;
            memset(a, 0, sizeof(a));
            cin >> n >> d;
            for (long long i = 1; i <= n; i++)
                cin >> a[i];
            for (long long i = 1; i <= n; i++)
            {
                for (long long j = i+1; j <= n; j++)
                {
                    if (check(i, j))
                        cnt ++;
                }
            }
            cout << cnt << endl;
        }
        return 0;
    }
    if (c == 11 || c == 12)
    {
        while (t--)
        {
            memset(a, 0, sizeof(a));
            cin >> n >> d;
            for (long long i = 1; i <= n; i++)
                cin >> a[i];
            long long d2 = a[2] - a[1];
            long long k = d/d2;
            if (k == 0 || k == 1)
            {
                cout << 0 << endl;
                continue;
            }
            if (k % 2 == 1)
            {
                if (n - (k+3) + 1 <= 0)
                {
                    cout << 0 << endl;
                    continue;
                }
                cout << n - (k+3) + 1 << endl;
                continue;
            }
            if (k % 2 == 0)
            {
                if (n - (k+2) + 1 <= 0)
                {
                    cout << 0 << endl;
                    continue;
                }
                cout << n - (k+2) + 1 << endl;
                continue;
            }
        }
    }
    return 0;
}
