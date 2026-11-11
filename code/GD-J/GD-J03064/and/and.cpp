#include <bits/stdc++.h>
using namespace std;
long long n,m, a[10000005], num;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    num = a[n];
    for (int i = 1; i <= m; i++)
    {
        num = num & a[n-i];
    }
    cout << num;
}

