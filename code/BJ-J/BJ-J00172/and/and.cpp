#include <bits/stdc++.h>
using namespace std;
int a[200005], maxn, andn, maxandn, tmp[32], cnt;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    a[0] = -1e9;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(a[i-1], a[i]);
        if(i == 1)andn = a[i];
        else andn = andn & a[i];
    }
    if(m == 1)
    {
        cout << maxn;
        return 0;
    }
    if(m == n)
    {
        cout << andn;
        return 0;
    }
    if(m == 2)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i+1; j <= n; j++)andn = max(andn, a[i] & a[j]);
        }
        cout << andn;
        return 0;
    }
    if(m == n-1)
    {
        for(int j = 2; j <= n; j++)
        {
            for(int i = 1; i <= n; i++)
            {
                if(i == j)continue;
                if(i == 1)andn = a[i];
                else andn = andn & a[i];
            }
            maxandn = max(andn, maxandn);
        }
        for(int i = 2; i <= n; i++)
        {
            if(i == 2)andn = a[i];
            else andn = andn & a[i];
        }
        maxandn = max(andn, maxandn);
        cout << maxandn;
        return 0;
    }
    tmp[0] = 1;
    for(int i = 1; i <= 30; i++)tmp[i] = tmp[i-1]*2;
    //for(int i = 1; i <= n; i++)cout << a[i] << ' ';
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 30; j++)
        {

            if(a[i] == tmp[j] - 1)
            {
                cnt++;
                //cout << a[i] << ' ' << tmp[j] << endl;
                break;
            }
        }
    }
    if(cnt == n)
    {
        sort(a + 1, a + 1 + n);
        //for(int i = 1; i <= n; i++)cout << a[i] << ' ';
        cout << a[n- m + 1];
        return 0;
    }
    bool f = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] != a[i-1] + 1)f = 0;
    }
    if(f == 1)cout << n - m;
    return 0;
}
