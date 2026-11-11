#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll read()
{
    ll x = 0, f =1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

const int MAXN = 5e5 + 5;
ll a[MAXN] = {0}, sum[MAXN] = {0};

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read();
    ll m = read();

    for (int i=1;i<=n;i++) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    
    vector<int> nxt;
    for (int i=1;i<=n;i++) {
        sum[i] = sum[i-1] + a[i];
        if (a[i+1] != a[i]) nxt.push_back(i);
    }

    int ans = 0;
    for (auto it=nxt.rend();it!=nxt.rbegin();it--) {
        int i = *it;
        for (int p=1;p<i;p++) {
            ll tot = sum[i-1] - sum[p-1];
            if (a[i] * (i-p) - tot <= m) {
                ans = max(ans, i - p + 1);
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}