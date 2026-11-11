#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, a[200005], posl, posr;
char c[200005];
ll ans;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    faster;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i] >> c[i];
    }
    posl = 1, posr = n;
    while (posl < posr) {
        int tmp = min(a[posl], a[posr]);
        if (c[posl] != c[posr]) ans += tmp;
        a[posl] -= tmp, a[posr] -= tmp;
        if (!a[posl]) ++ posl;
        if (!a[posr]) -- posr;
    }
    cout << ans;
    return 0;
}//made_by_zap2727
