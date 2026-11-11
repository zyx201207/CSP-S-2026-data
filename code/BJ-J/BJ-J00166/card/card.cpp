#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500003];
vector<long long> vec;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<long long, long long> mp;
    for (int i = 1; i <= n; i++) {
        vec.clear();
        for (int j = i; j <= n; j++) {
            long long num = a[j];
            bool flag = false;
            long long id = 0;
            for (long long k : vec) {
                id++;
                if (k == num) {
                    flag = true;
                    vec.erase(vec.begin() + id - 1, vec.end());
                    break;
                }
            }
            vec.push_back(a[j]);
        }
        for (int k : vec) {
            mp[k]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << mp[i] << ' ';
    }

    return 0;
}
