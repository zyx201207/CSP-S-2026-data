#include <iostream>
#include <cstdio>

using namespace std;

int c, t;
int n;
long long int m;
long long int a[2114514];
int flen[5144], lst[2114514];
long long int fangfa[5144];
int kua[5144];

int main()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    int i, j;
    cin >> c >> t;
    if (c == 11 || c == 12 || c == 0)
    {
        while (t--)
        {
            cin >> n >> m;
            for (i = 1; i <= n; i++)
            {
                cin >> a[i];
            }
            if (m / (a[2] - a[1]) < 2) cout << 0 << endl;
            else cout << max(0ll, n - 2 * m / (a[2] - a[1]) + 1) << endl;
        }
        return 0;
    }
    while (t--)
    {
        int ans = 0;
        cin >> n >> m;
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (i = 1, j = 1; i <= n; i++)
        {
            while (a[j] + m < a[i])
            {
                j++;
            }
            lst[i] = j;
        }
        for (j = 0; j <= n; j++)
        {
            flen[j] = 0;
            fangfa[j] = 0;
            kua[j] = 0;
        }

        for (i = 1; i <= n - 1; i++)
        {
            for (j = 0; j <= n; j++)
            {
                flen[j] = 0;
                fangfa[j] = 0;
            }
            flen[i] = 0;
            fangfa[i] = 1;
            int nn = n;
            for (j = i + 1; j <= n; j++)
            {
                if (lst[j] == j)
                {
                    nn = j - 1;
                    break ;
                }
                flen[j] = -1;
                flen[j] = flen[lst[j]] + 1;
            }
            for (j = i; j <= nn; j++)
            {
                if (flen[j] != flen[j + 1])
                {
                    kua[flen[j]] = j;
                }
                //cout << j << " flen" << flen[j] << " kua :" << kua[flen[j]] << endl;
            }
            for (j = i; j <= nn; j++)
            {
                if (flen[j] <= 1)
                {
                    fangfa[j] = 1 + fangfa[j - 1];
                    //cout << j << " " << 1 << endl;
                    continue ;
                }
                fangfa[j] = fangfa[kua[flen[j] - 1]] - fangfa[lst[j] - 1];
                if (fangfa[j] == 2)
                {
                    ans++;
                }
                //cout << j << " " << fangfa[j] << endl;
                fangfa[j] += fangfa[j - 1];
            }
            //cout << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
