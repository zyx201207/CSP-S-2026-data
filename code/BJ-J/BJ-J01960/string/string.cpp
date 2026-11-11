#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int n, a[MAX];
char c[MAX];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];
    for (int i = 1, j = n; i < j; ) {
        int len = min(a[i], a[j]);
        if (c[i] != c[j]) ans += len;
        a[i] -= len;
        a[j] -= len;
        if (!a[i]) i++;
        if (!a[j]) j--;
    }
    cout << ans << '\n';
    return 0;
}
