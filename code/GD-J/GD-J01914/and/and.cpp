#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
            if (ans < a[i])
                ans = a[i];
    }
    cout << ans;
    return 0;
}
