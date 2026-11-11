#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n;
    long long m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int h = 0;
    int ct = 0;
    int nw = 0;
    for(int i = 1; i < n; ++i) {
        nw = nw + (i - h) * (a[i] - a[i-1]);
        while(m < nw) {
            ++h;
            nw = nw - a[i] + a[h];
        }
        if(i - h + 1 > ans) {
            ans = i - h + 1;
        }
    }
    cout << ans;
    return 0;
}