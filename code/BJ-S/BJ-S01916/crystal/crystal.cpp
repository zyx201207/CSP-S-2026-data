#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n = 0;
long long m = 0;
long long a[500009] = {};
long long _res = 0;

int main () {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
//        d[i] = a[i] - d[i - 1];
    }

    sort(a + 1, a + n + 1);
    for (int i = a[2]; i <= a[n]; i++) {
        long long d[500009] = {};
        for (int j = 1; j <= n; j++) {d[j] = a[j];}
        long long sum = m;
        long long cc = 1;
        while (sum > 0 && cc <= n && a[cc] < i) {
            if (sum - (i - a[cc]) > 0) {
                d[cc] = i;
                sum -= (i - a[cc]);
                cc++;
            }
            else {
                d[cc] += sum;
                sum = 0;
                break;
            }
        }

        map<long long, int> mp;
        long long res = 0;
        for (int j = 1; j <= n; j++) {
//            cout << d[j] << " ";
            mp[d[j]]++;
        }
//        cout << endl;
        for (auto v:mp) {
            if (v.second <= 1) {
                continue;
            }
            res += v.second;
        }
        if (res > _res) {
            _res = res;
        }
    }

    cout << _res << endl;

    return 0;
}

