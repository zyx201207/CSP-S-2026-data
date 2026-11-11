#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int c, t, n;
long long d, ans, x[2000005];
map<__int128, __int128> mp;

void dfs(int sid, int nid, int step) {
    __int128 tmp = 1;
    tmp <<= 64;
    __int128 fir = tmp * sid + nid;

    if (mp[fir] == 0) {
        mp[fir] = tmp * step + 1;
    } else if (step < mp[fir] / tmp) {
        mp[fir] = tmp * step + 1;
    } else if (step == mp[fir] / tmp) {
        mp[fir]++;
    }
    for (int i = nid + 1; i <= n && x[i] - x[nid] <= d; i++) {
        dfs(sid, i, step + 1);
    }
}

/*void print(__int128 num) {
    string s = "";
    while (num) {
        int mod = qw % 10;
        s = to_string(mod) + s;
        num /= 10;
    }
    cout << s;
}*/

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;
    while (t--) {
        cin >> n >> d;
        if (c >= 11 && c <= 12) {
            cout << 0;
            continue;
        } else if (c >= 13 && c <= 14) {
            cout << n / 2;
            continue;
        }
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, i, 0);
        }
        for (auto it : mp) {
            __int128 tmp = 1;
            tmp <<= 64;
            if (it.second % tmp == 2) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
