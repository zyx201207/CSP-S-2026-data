#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int imax = 2147483647;
int po2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
int n, m, ans;
int a[N];
bool vis[N];

// --B--
vector<int> opB;
bool visB[N];
// -----


void dfs(int step, int now) { // 在不满足性质A和B时使用  O(n ^ m)
    if (step > m) {
        ans = max(ans, now);
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(step + 1, now & a[i]);
        vis[i] = 0;
    }
}
int find2(int x) { // 找x变为二进制后一的个数
    int t = x;
    string s = "";
    while(t) {
        s += (t % 2 + '0');
        t /= 2;
    }
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') cnt++;
    }
    return cnt;
}
bool cmp(int x, int y) {
    if (find2(x) != find2(y))
        return find2(x) > find2(y);
    return x > y;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool fA = 1, fB = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // 特判性质A
            bool ok = 0;
            for (int j = 0; j <= 20; j++) {
                if (a[i] == po2[j] - 1){
                    ok = 1;
                    break;
                }
            }
            if (!ok) fA = 0;
        // 特判性质B
            if (a[i] != i - 1) fB = 0;
    }
    if (m == 1) {
        int maxn = -imax;
        for (int i = 1; i <= n; i++) {
            maxn = max(maxn, a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    if (fA) { // A
        sort(a + 1, a + n + 1);
        int ansA = a[n];
        for (int i = n - 1; i >= n - m + 1; i--) {
            ansA &= a[i];
        }
        cout << ansA << endl;
        return 0;
    }
    if (n == m) {
        int ans1 = a[1];
        for (int i = 2; i <= n; i++) {
            ans1 &= a[i];
        }
        cout << ans1 << endl;
        return 0;
    }
    if (n - 1 == m) {
        int minn = imax;
        for (int i = 1; i <= n; i++) {
            int ans;
            if (i == 1) ans = a[2];
            else ans = a[1];
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                ans &= a[j];
            }
            minn = min(minn, ans);
        }
        cout << minn << endl;
        return 0;
    }
    if (fB) { // B
        for (int i = n; i >= 1; i--) {
            if (opB.size() == m) break;
            for (int j = 0; j <= 20; j++) {
                if (a[i] != 0 && a[i] == po2[j] - 1 && opB.size() < m) {
                    opB.push_back(a[i]);
                    visB[i] = 1;
                }
            }
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            if (visB[i]) continue;
            opB.push_back(a[i]);
        }
        int ansB = opB[0];
        for (int i = 1; i < opB.size(); i++) {
            ansB &= opB[i];
        }
        cout << ansB << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dfs(2, a[i]);
        vis[i] = 0;
    }
    cout << ans << endl;
    return 0;
}
