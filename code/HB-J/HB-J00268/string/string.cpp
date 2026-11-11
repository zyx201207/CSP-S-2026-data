#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, a[N];
char c[N];
long long res = 0;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for(int i = 1;i <= n;++ i)
    {
        cin >> a[i] >> c[i];
    }

    int l = 1, r = n;

    while(l < r)
    {
        if(c[l] != c[r])
        {
            if(a[l] <= a[r])
            {
                a[r] -= a[l];
                res += a[l];
                a[l] = 0;
                l ++;
                if(a[r] == 0) r --;
            }
            else
            {
                a[l] -= a[r];
                res += a[r];
                a[r] = 0;
                r --;
                if(a[l] == 0) l ++;
            }
        }else
        {
            if(a[l] <= a[r])
            {
                a[r] -= a[l];
                a[l] = 0;
                l ++;
                if(a[r] == 0) r --;
            }else
            {
                a[l] -= a[r];
                a[r] = 0;
                r --;
                if(a[l] == 0) l ++;
            }
        }
    }

    cout << res;

    return 0;
}
