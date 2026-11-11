#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
long long a[N];
long long sum[N];

int main() {

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];

    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        //the last number is a[i]
        int lenl = 1, lenr = i + 1;
        while(lenr - lenl > 1) {
            int mid = (lenl + lenr) / 2;
            if(-sum[i] + sum[i - mid] + a[i] * mid <= m) lenl = mid;
            else lenr = mid;
        }
        mx = max(mx, lenl);
    }

    cout << mx;

    return 0;
}
