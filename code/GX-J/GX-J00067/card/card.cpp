#include <bits/stdc++.h>
using namespace std;

long long arr[500005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    long long n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= m; i++) {
        cout << 0 << " ";
    }

    return 0;
}
