#include <iostream>
using namespace std;
long long lst[500010], cnt[500010];
long long a[500010], sa[500010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        lst[a[i]] = i;
        sa[a[i]]++;
    }
    for(int i = 1; i <= m; ++i) {
        int j = lst[i];
        while(j <= n) {
            cnt[a[j]] += sa[i];
            j = lst[a[j]] + 1;
        }
    }
    for(int i = 1; i < m; ++i)
        cout << cnt[i] << ' ';
    cout << cnt[m];
    return 0;
}
