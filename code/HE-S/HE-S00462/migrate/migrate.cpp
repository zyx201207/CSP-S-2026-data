#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
int x[100005];
int cal (int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (x[i] - x[i - 1] > d)
        {
            cnt++;
        }
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
void op()
{
    memset (x, n, 0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    int sum = cal(n);
    cout << sum << endl;
    return ;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t > 0)
    {
        t--;
        op();
    }
    return 0;
}
