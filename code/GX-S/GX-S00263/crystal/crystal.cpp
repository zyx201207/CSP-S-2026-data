#include <bits/stdc++.h>>

using namespace std;

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    long long a[n+1] = {0};
    for(int i = 1;i <= n;i++)
        cin >> a[i];

    int mx = 1;
    long long js = 0;
    int js2 = 1;
    sort(a, a+n+1);
    for(int i = n;i >= mx+1;i--)
    {
        for(int j = i;j >= 2;j--)
        {
            if(js + (a[i] - a[j-1]) <= m)
            {
                js2++;
                js += (a[i] - a[j-1]);
            }
            else
                break;
        }
        mx = max(mx, js2);
        js = 0;
        js2 = 1;
    }
    cout << mx;
    return 0;
}
