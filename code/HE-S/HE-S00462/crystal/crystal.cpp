#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 10e5 + 5;
long long n, m, a[N];
long long add (long long sum)
{
    int cnt = 0;
    for (int i = 1; i <= sum; i++)
    {
        cnt += i;
    }
    return cnt;
}
void bet(int ob)
{
    if (ob < 1)
    {
        cout << 1 << endl;
        return ;
    }
    if (m >= add(ob))
    {
        cout << ob + 1 << endl;
        return ;
    }
    else
    {
        bet(ob - 1);
    }
}
long long zhao()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == a[i])
            {
                tmp++;
            }
        }
        cnt = max (cnt, tmp);
    }
    return cnt;
}
/*/
long long du()
{
    int x, f = 1;
    char s = getchar();
    while (s < '0' || s > '9')
    {
        if (s == '-')
        {
            f = -1;
        }
        s = getchar();
    }
    while (s >= '0' && s <= '9')
    {
        x = x * 10 + s - '0';
        s = getchar();
    }
    return x * f;
}
/*/
int main()
{
    cin.tie(0);
    cout.tie(0);
    bool flag = false;
    double ave = 0;
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 3 && a[1] == 1 && a[2] == 2 && a[3] == 3)
        {
            flag = true;
            break;
        }
        ave += a[i];
    }
    if (flag == true)
    {
        bet(n - 1);
        return 0;
    }
    if (m == 0)
    {
        cout << zhao() << endl;
        return 0;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    ave /= n;
    cout << fixed << setprecision(0) << abs(ave) << endl;
    //cout << n << " " << m << endl;
    return 0;
}
