#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e5 + 25;
int card[maxn], que[maxn], tail, pos[maxn];
bitset<maxn> ontable;   // ontable[x] means card with the number x is on the table.
int ans[maxn], n, m;

void play(int st) {
    tail = 0;
    ontable.reset();
    fill(pos + 1, pos + m + 1, 0);
    for (int xid = st; xid <= n; ++xid) {
        auto x = card[xid];
        if (ontable[x]) {
            auto px = pos[x];
            for (int i = px; i <= tail; ++i) {
                auto y = que[i];
                ontable[y] = false;
                pos[y] = 0;
            }
            tail = px - 1;
        }
        ++tail;
        pos[x] = tail;
        que[tail] = x;
        ontable[x] = true;
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> card[i];
    }
    for (int i = 1; i <= n; ++i) {
        play(i);
        for (int x = 1; x <= m; ++x) {
            ans[x] += (ontable[x] ? 1 : 0);
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << " \n"[i == m];
    }
    return 0;   
}