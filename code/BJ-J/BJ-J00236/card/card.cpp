#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N];
int n, m;
vector<int> ans[N]; // ans[i]表示在第i局中留下了什么
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int play = 1; play <= n; play++) {
        // 开始出牌(前i - 1跳过)
        int now[N] = {};
        bool app[M] = {}; // 桌上有的牌
        int pos[M] = {}; // pos[i]表示第i种牌的位置
        int cur = 0;
        memset (pos, -1, sizeof pos);
        for (int i = play; i <= n; i++) {
            if (app[a[i]]) {
                cur = pos[a[i]];
                pos[a[i]] = -1;
                app[a[i]] = 0;
            }
            app[a[i]] = 1;
            now[cur++] = a[i];
            pos[a[i]] = cur - 1;
        }
        for (int i = 0; i < cur; i++) {
            ans[play].push_back(now[i]);
            //cout << now[i] << " ";
        }
        //cout << endl;
    }
    for (int i = 1; i <= m; i++) {
        int cnt = 0;
        for (int k = 1; k <= n; k++) {
            for (int j = 0; j < ans[k].size(); j++) {
                if (ans[k][j] == i)  {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << " ";
    }
    return 0;
}
