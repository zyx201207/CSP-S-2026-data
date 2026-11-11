#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010], sa[500010];

inline int read(){
    int x=0, f=1;
    char ch = getchar();
    while (!isdigit(ch)){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)){
        x = x*10 + (ch^48);
        ch = getchar();
    }
    return x*f;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();

    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) sa[i] = sa[i-1]+a[i];

    int l = 1, r = 1, ans = 1;
    while (l <= r){
        while (r+1 <= n && a[r+1]*(r-l+2) - sa[r+1]+sa[l-1] <= m) r++;
        ans = max(ans, r-l+1);
        l++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}