#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 500005;
long long a[Maxn], pre[Maxn];
long long add(long long x, long long id)
{
    long long ans;
    ans = id * x - pre[id];
    return ans;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int x = add(a[mid], mid);
        if (x <= m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1;
}
