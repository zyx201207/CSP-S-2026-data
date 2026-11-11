#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int sum = a[n];
    for (int i = n;i >= n - m + 1;i--)
    {
        sum = sum & a[i];
    }
    cout << sum << endl;
}
