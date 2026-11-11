#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
int m, n;
long long a[MAX_N];
long long vis[MAX_N];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    for (int i=0; i<=29; i++) {
        ans += pow(2, i);
    }

    while (m--) {
        long long temp = ans;
        int index = 0;
        for (int i=0; i<n; i++) {
            if (vis[i] == 0) {
                temp &= a[i];
                index = i;
                break;
            }
        }

        for (int i=0; i<n; i++) {
            if (ans & a[i] > temp && vis[i] == 0) {
                index = i;
                temp = ans & a[i];
            }
        }
        ans = temp;
        vis[index] = 1;
    }
    cout << ans << endl;
    return 0;
}
