#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+5;
int n, m;
int a[N];
int dp[N];
bool ok;
int sum;

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int l=1, r=2, maxn=1;
    for(;l<r&&l<=n; l++) {
        while(r<=n && sum+(a[r]-a[r-1])*(r-l)<=m) {
            sum = sum+(a[r]-a[r-1])*(r-l);
            r ++;
        }
        if(sum+(a[r]-a[r-1])*(r-l) > m) {
            maxn = max(maxn, r-l);
        }
        l ++;
        sum -= (a[r-1]-a[l]);
    }
    cout << maxn;
    fclose(stdin);
    fclose(stdout);
}
