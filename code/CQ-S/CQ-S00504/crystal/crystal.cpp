#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 5e5 + 10;
int n;
ll k;
ll a[N];
ll sum[N];
/*
*/

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int l = 1, r = i - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= k) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans << endl;
    cerr << "----TIMES: " << clock() << endl;
    return 0;
}
// 谨记：空间一定要算一遍大小；大样例过了一定要回测小样例；造corner case测边界；不要死磕！！
// 注意时间安排
// trust your self
/*
正在比较文件 crystal1.txt 和 CRYSTAL1.ANS
FC: 找不到差异

正在比较文件 crystal2.txt 和 CRYSTAL2.ANS
FC: 找不到差异

正在比较文件 crystal3.txt 和 CRYSTAL3.ANS
FC: 找不到差异

正在比较文件 crystal4.txt 和 CRYSTAL4.ANS
FC: 找不到差异
*/



















/*
今天是 Xterfusion 发布一周年的日子，前面忘了后面忘了，有他有我还有你。

Only feels like nothing could be better when I with you, when I with you~

X X XXX

*/