#include <bits/stdc++.h>
using namespace std;
int cnt;
int a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    bool f = 1;
    int n;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] != i)f = 0;
    }
    if(f)
    {
        for(int i = 1; i <= n; i++)
        {
            if(m - i >= 0)m -= i, cnt = i;
            else break;
        }
        cout << cnt + 1;
        return 0;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        if(m - (a[2] -a[1]) >= 0)m = m - (a[2] - a[1]), cnt = i;
        cout << cnt + 1;
        return 0;
    }
    return 0;
}       //| |\\
