// 15.46 16.23
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;

int T, n; ll d, ans;
ll a[N]; int l[N], r[N], dr[N];
ll f1[N], f2[N];

void clear() {
    ans = 0;
    for(int i = 0; i <= n + 2; i++) a[i] = f1[i] = f2[i] = l[i] = r[i] = dr[i] = 0;
}

int main() {

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> T;
    while(T--) {
        cin >> n >> d; clear();
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1, j = 1; i <= n; i++) {
            while(a[i] - a[j] > d) ++j;
            if(j != i) l[i] = j;
        }
        for(int i = n, j = n; i >= 1; i--) {
            while(a[j] - a[i] > d) --j;
            if(j != i) r[i] = j;
        }
        for(int i = 1; i <= n; i++) if(r[i]) dr[r[i]]++;
        for(int i = 1; i <= n; i++) {
            if(!l[i]) continue;
            if(l[i] < i - 1) ans += dr[l[i] + 1] - (r[l[i]] == l[i] + 1);
            f1[i] = dr[i] + (r[l[i]] == i ? f1[l[i]] : 0ll);
            if(r[l[i]] == i && l[i] < i - 1 && r[l[i] + 1] == i) f2[i] = dr[l[i] + 1];
            f2[i] += (r[l[i]] == i ? f2[l[i]] : 0ll);
            if(r[l[i]] == i && l[i] < i - 1 && r[l[l[i] + 1]] == l[i] + 1 && r[l[i] + 1] == i && l[l[i]] == l[l[i] + 1])
                f2[i] += f1[l[l[i]]];
            if(l[i] < i - 1 && r[l[l[i] + 1]] == l[i] + 1 && l[l[i]] == l[l[i] + 1]) ans += f1[l[l[i]]];
            ans += f2[l[i]];
        }
        // for(int i = 1; i <= n; i++) {
        //     cout << f1[i] << ' ' << f2[i] << endl;
        // }
        cout << ans << '\n';
    }

    return 0;
}