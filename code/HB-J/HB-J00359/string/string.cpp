#include <bits/stdc++.h>
using namespace std;
int n, a, ans;
string s;
void dfs(int l, int r){
    if (l > r) return;
    if (l == r){
        if (s[l] != s[n-l-1]) ans++;
        return;
    }
    int m = (l + r) >> 1;
    dfs(l, m);
    dfs(m+1, r);
}
string mkstr(string c, int a){
    if (a == 1){
        return c;
    }
    return mkstr(c, a >> 1) + mkstr(c, (a + 1) >> 1);
}
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    {
        int sum; string c;
        while (n--){
            cin >> a >> c;
            sum += a;
            s += mkstr(c, a);
        }
        n = sum;
    }
    cout << n << '\n';
    dfs(0, n >> 1);
    cout << ans;
    return 0;
}
