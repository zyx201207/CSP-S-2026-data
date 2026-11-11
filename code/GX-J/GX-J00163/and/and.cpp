#include<bits/stdc++.h>
using namespace std;

int a[200005];
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if(n == m)
    {
        int ans = a[1];
        for(int i = 2; i <= n; i++)
        {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }


    int maxn = -999;
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int an = a[i] & a[j];
            if(an > maxn)
            {
                maxn = an;
            }
        }
    }
        cout << maxn;
    return 0;
}
