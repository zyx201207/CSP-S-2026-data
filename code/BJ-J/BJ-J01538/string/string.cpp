#include <bits/stdc++.h>

using namespace std;

const int maxn = 200007;

long long ans;
int a[maxn];
char c[maxn];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++ ) cin >> a[i] >> c[i];

    int head = 1, tmp = n;
    while (head < tmp)
    {
        if (c[head] == c[tmp])
        {
            if (a[head] < a[tmp])
            {
                a[tmp] -= a[head];
                head ++ ;
            }
            else if (a[head] > a[tmp])
            {
                a[head] -= a[tmp];
                tmp -- ;
            }
            else if (a[head] == a[tmp])
            {
                tmp -- ;
                head ++ ;
            }

        }
        else if (a[head] < a[tmp])
        {
            ans += a[head];
            a[tmp] -= a[head];
            head ++ ;
        }
        else if (a[head] > a[tmp])
        {
            ans += a[tmp];
            a[head] -= a[tmp];
            tmp -- ;
        }
        else if (a[head] == a[tmp])
        {
            ans += a[tmp];
            head ++ ;
            tmp -- ;
        }
    }

    cout << ans << endl;

    return 0;
}
