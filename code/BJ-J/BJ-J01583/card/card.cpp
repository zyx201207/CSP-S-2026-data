#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;
int n, m, a[N], ans[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int K = 1; K <= n; K++) { // 游戏第 K 轮
        unordered_map<int, int> mp; // 上一次出现的卡牌坐标
        for (int i = K; i <= n; i++) mp[a[i]] = -1;
        for (int i = K; i <= n; i++) {
            if (mp[a[i]] != -1) {
                for (auto& p : mp) {
                    if (p.first != a[i] && p.second < i && p.second > mp[a[i]]) mp[p.first] = -1;
                }
            }
            mp[a[i]] = i;
        }
        for (auto& p : mp) {
            if (p.second != -1) ans[p.first]++;
        }
        //printf("%d ", ans);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}

// Trick or Treat!

