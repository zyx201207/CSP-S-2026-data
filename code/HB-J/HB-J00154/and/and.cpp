#include<bits/stdc++.h>
using namespace std;

int n, m;
long long maxx, all=pow(2, 40)-1, minn;
long long a[10000+10];
long long maxxans =0;
long long a1[30];
void dfs(int pos) {
    if(pos == n+1) {
        long long maxxns = 1099511627775, ok = 0;
        for(int i = 1;i<=n;i++) {
            ok += a1[i];
            if(a1[i] == 1){
                maxxns = (maxxns & a[i]);
            }
        }
        if(ok != m) return;
        if(ok == m) {
            maxxans = max(maxxans, maxxns);
        }
        return;
    }
    a1[pos] = 1;
    dfs(pos+1);
    a1[pos] = 0;
    dfs(pos+1);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
        maxx=max(maxx, a[i]);
        minn = min(minn, a[i]);
        all = all & a[i];
    }
    if(m == 1) {
        cout << maxx;
        return 0;
    }
    if(m==n) {
        cout << all;
        return 0;
    }
    if(m == 2) {
        long long x = 0;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                if(i != j) {
                    x = max(x, a[i] & a[j]);
                }
            }
        }
        cout << x;
        return 0;
    }
    if(n <= 20) {
        dfs(1);
        cout << maxxans;
        return 0;
    }
    cout << minn;
}
