#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;

int n, m, ans;
int a[maxn], vis1[maxn], vis2[maxn], pw[40];

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vis1[i] = 1;
	}
    pw[0] = 1;
    for (int i = 1; i <= 32; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
	for (int i = 31; i >= 0; --i) {
		memset(vis2, 0, sizeof(vis2));
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
//        	printf("%d %d %d %d\n", i, vis1[j], a[j], bool((a[j] >> i) == 1));
            if (vis1[j] && (a[j] & pw[i])) { 
                vis2[j] = 1;
                ++cnt;
            }
        }
//        printf("%d %d\n", i, cnt);
        if (cnt >= m) {
            ans += pw[i];
            for (int j = 1; j <= n; ++j) {
                vis1[j] = vis2[j];
            }
        }
    }
    cout << ans;
    return 0;
}
/*
思路：
容易想到n^2dp
f[i][j]表示前i个数，选了j个时与起来的最大值
f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] & a[i])
看起来非常没有前途
考虑如何利用与的性质
若答案第i位为1，那么选择的m个数的第i位也一定都为1
并且越高位越大
那么考虑贪心
从第i位开始考虑，高到低 
如果可以在第i位找到>=m个数（第i位为1），那么这一位可以产生贡献，且一定比后面所有位加起来的大，必选  
那么继续考虑后面的位数， 判断在这些已经选过的数中的贡献
 5 3
31 3 1 15 7
*/
