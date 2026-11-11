#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "W", stdout);
    int n, m, sum = 1;
    cin >> n >> m;
    long long a[50005];
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    sum = a[0];
    for(int i = 1;i < m;i++)
    {
        sum &= a[i];
    }
    cout << sum;
    return 0;
}
