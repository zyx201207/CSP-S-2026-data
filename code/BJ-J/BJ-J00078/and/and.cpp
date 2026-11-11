#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n, m, a[N];
long long ans[N], maxn = -100;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            ans[i] = a[i]&a[j];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        maxn = max(maxn, ans[i]);
    }
    cout << maxn;

    return 0;
}


