#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 2;i <= n;i++) {
        if (a[i] != a[i - 1]) {
            cout << i - 1 << " ";
        }
    }
    cout << n;
    return 0;
}
