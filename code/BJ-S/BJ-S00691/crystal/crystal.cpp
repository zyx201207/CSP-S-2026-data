#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0 ; i < n; i ++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int k = n / 2, cnt = 0;
    if (n % 2 == 1) {
        vector<int> cha(n);
        for (int i = 0; i < n ; i ++) {
            cha[i] = v[k] - v[i];
        }
        int ans = m;
        for (int i = k; i >= 0; i --) {
            if (cha[i] >= 0) {
                ans -= cha[i];
                if (ans >= 0)
                    cnt ++;
            }
        }
        for (int i = k + 1; i < n; i ++) {
            if (cha[i] >= 0) {
                ans -= cha[i];
                if (ans >= 0)
                    cnt ++;
            }
        }
    } else {
        vector<int> cha(n);
        for (int i = 0; i < n ; i ++) {
            cha[i] = v[k] - v[i];
        }
        int c = 0, ans = m;
        for (int i = k; i >= 0; i --) {
            if (cha[i] >= 0) {
                ans -= cha[i];
                if (ans >= 0)
                    c ++;
            }
        }
        for (int i = k + 1; i < n; i ++) {
            if (cha[i] >= 0) {
                ans -= cha[i];
                if (ans >= 0)
                    c ++;
            }
        }
        //--------------------------------------------
        int c2 = 0;
        ans = m;
        vector<int> cha2(n);
        for (int i = 0; i < n ; i ++) {
            cha2[i] = v[k - 1] - v[i];
        }
        for (int i = k - 1; i >= 0; i --) {
            if (cha2[i] >= 0) {
                ans -= cha2[i];
                if (ans >= 0)
                    c2 ++;
            }
        }
        for (int i = k; i < n; i ++) {
            if (cha2[i] >= 0) {
                ans -= cha2[i];
                if (ans >= 0)
                    c2 ++;
            }
        }
        cnt = max(c, c2);
    }
    cout << cnt;
    return 0;
}
