#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int c, T, n, d, a[N], nxt[N], dp1[N], dp2[N], ans;

void solve() {
    cin >> n >> d;
    bool flag = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
            flag = 0;
        }
        nxt[i] = 0;
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    if(flag) {
        if(n >= 4 && a[3] - a[1] <= d) {
            int j;
            for(j = 3; j <= n && a[j] - a[1] <= d; j++);
            cout << max(0ll, n - (j - 2) * 2 + 1) << "\n";
        }
        else {
            cout << "0\n";
        }
        return;
    }
    for(int i = 1, j = 1; i <= n; i++) {
        while(a[j + 1] - a[i] <= d && j + 1 <= n) {
            j++;
        }
        if(j > i) {
            nxt[i] = j;
        }
    }
    ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            dp1[j] = 1e18;
            dp2[j] = 0;
        }
        dp1[i] = 0;
        dp2[i] = 1;
        for(int j = i; j <= n; j++) {
            ans += dp2[j] == 2;
            if(dp2[j] <= 2) {
                for(int k = max(nxt[j] - 2, j + 1); k <= nxt[j]; k++) {
                    if(dp1[k] > dp1[j] + 1) {
                        dp1[k] = dp1[j] + 1;
                        dp2[k] += dp2[j];
                    }
                    else if(dp1[k] == dp1[j] + 1) {
                        dp2[k] += dp2[j];
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> c >> T;
    while(T--) {
        solve();
    }

    return 0;
}

/*
我讨厌计数题www
完了正解我怎么就是想不出来
要退役了呜呜呜
欸暴力有40分我好像有救了
分叉的标志就是nxt[i]-i>=2
然后左边会有连续的一段nxt[i]=i+1的数字,这些数字作为起点都是可以的.然后不能够越过另外一个这类型的分叉?
好像分叉会重叠怎么办
分类讨论一下:不重叠的,就是互相不可跨过,并且如果分叉的两个点的nxt不同,则右边界进一步压缩至min(nxt)
重叠的...好像不需要考虑重叠的影响?
会互相影响的分叉需要的条件是什么?
1. 前面那个分叉已经闭合,显然会造成影响
2. 未闭合的似乎也有影响?
难道说,如果有两个分叉,前面的包含后面的任意一个分叉点,那么就没有影响?
我发现了!这个情况下,后面的分叉没有贡献;前面的分叉可以跨过后面的分叉!
也就是说,后面那个分叉不做数?似乎是这样的.写写试试先
完了样例1就 hack 掉了
还是要打暴力啊
完了条不完了
*/