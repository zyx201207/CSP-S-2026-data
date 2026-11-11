#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
vector<long long> a;
vector<long long> pre;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;

    a.resize(n); pre.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        long long ai;
        cin >> ai;
        a[i] = ai;
    }

    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    int l = 0, r = 0;
    long long need_increase = 0;
    while (r <= n) {
        if (need_increase <= m) {
            ans = max(ans, r - l);
            r++;
        } else if (l < r) {
            l++;
        }
        
        if (r <= n) {
            long long pre_sum = pre[r] - pre[l];
            long long up_sum = a[r - 1] * (r - l);
            need_increase = up_sum - pre_sum;
        }
    }

    cout << ans;

    return 0;
}