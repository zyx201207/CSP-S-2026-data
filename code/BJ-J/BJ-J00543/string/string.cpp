#include<bits/stdc++.h>
using namespace std;

struct ch {
    int x;
    char c;
};

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long maxn = 0;
    long long ans = 0;
    cin >> n;
    ch a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].c;
        maxn = maxn + a[i].x;
    }
    char cn[maxn];
    long long nw = 0;
    for(int i = 0 ;i < n; ++i) {
        for(int j = 0; j < a[i].x; ++j) {
            cn[nw+j] = a[i].c;
        }
        nw = nw + a[i].x;
    }
    for(int i = 0; i <= maxn / 2; ++i) {
        if(cn[i] != cn[maxn-i-1]) {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}