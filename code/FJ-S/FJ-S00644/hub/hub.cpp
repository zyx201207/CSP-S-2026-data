#include<bits/stdc++.h>
#define int long long
using namespace std;



signed main() {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int a[10] = {1, 2, 3, 4, 5};
    cout << *(lower_bound(a, a + 5, 3)) << ' ' << *upper_bound(a, a + 5, 3);

    return 0;
}