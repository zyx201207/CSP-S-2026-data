#include <bits/stdc++.h>

using namespace std;

const int maxn = 200007;

int a[maxn], cnt[maxn], anscnt[maxn], ans[maxn];
long long ansans;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int mx = -1;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        anscnt[i] = a[i];
        mx = max(mx, a[i]);
    }

    int len = 0;
    while (mx)
    {
        len ++ ;
        mx /= 2;
    }

    int anslen = len, k = n;
    while (len -- )
    {
        int sum = 0;
        for (int i = 1; i <= k; i ++ )
            if ((anscnt[i] >> len) % 2 == 1)
                cnt[ ++ sum] = anscnt[i];

        if (sum > m)
        {
            k = sum;
            ans[len + 1] = 1;
            for (int i = 1; i <= sum; i ++ ) anscnt[i] = cnt[i];
        }
        else if (sum < m) continue;
        else if (sum == m)
        {
            k = sum;
            ans[len] = 1;
            for (int i = 1; i <= sum; i ++ ) anscnt[i] = cnt[i];
            len -- ;
            break;
        }
    }

    int tmp = anslen;
    while (tmp)
    {
        ans[tmp] = 1;
        for (int j = 1; j <= k; j ++ )
        {
            if ((anscnt[j] >> (tmp - 1)) % 2 == 0) ans[tmp] = 0;
        }
        tmp -- ;
    }

    tmp = 1;
    for (int i = 1; i <= anslen; i ++ )
    {
        if (ans[i] == 1) ansans += tmp;
        tmp *= 2;
    }

    cout << ansans << endl;

    return 0;
}
