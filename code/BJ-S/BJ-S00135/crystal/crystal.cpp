#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long maxn = 0;
    for (int i = n; i >= 1;i--)
    {
        long long c = m;
        long long ans = 1;
        for (int j = i - 1;j >=1; j--)
        {
            if (c >= a[i] - a[j] && c > 0)
            {
                ans ++;
                c-=a[i] - a[j];
                if (ans > maxn)
                    maxn = ans;
            }
            else
            {
                break;
            }
        }
    }
    cout << maxn;
    return 0;
}
