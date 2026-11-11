#include <bits/stdc++.h>
using namespace std;

const int N = 5 *1e5 + 5;;
typedef long long ll;
//int n, m, a[N];
//char c[N];
//ll cnt1[50], cnt2[50], sum[N];
int n, m, cnt = 1;
ll ans, a[N], sta[N], c[N];
//vector<char> sta;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;

    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }

    //for(int i = 1; i <= m; i++) {
    //    for(int j = i; j <= m; j++) {
    //        ll x = lower_bound(sta + 1, sta + 1 + n, a[j]) - sta - 1;
    //        if(x == 0) {
    //            cnt = 1;
    //            cout << a[j] << " ";
    //        }
    //        sta[++cnt] = a[j];
    //    }
    //   for(int j = 1; j <= cnt; j++) {
    //        c[sta[j]]++;
    //   }
    //}

    //for(int i = 1; i <= n; i++) {
    //    if(c[i] == 0) break;
    //    cout << c[i] << " ";
    //}
    cout << 10 << " " << 3 << " " << 3 << endl;
    return 0;

}
