#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 25;

int n;
pair<int, char>d[MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> d[i].first >> d[i].second;
    }
    ll ans = 0;
    for(int L = 1, R = n; L < R;) {
        //cout << L << ' ' << R << ' ' << d[L].first << ' ' << d[R].first << '\n';
        int chg = min(d[L].first, d[R].first);
        d[L].first -= chg, d[R].first -= chg;
        if(d[L].second != d[R].second)ans += chg;
        if(d[R].first == 0)R--;
        if(d[L].first == 0)L++;
    }
    cout << ans;
    return 0;
}
