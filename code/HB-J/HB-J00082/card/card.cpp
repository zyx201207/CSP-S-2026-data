# include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], cnt[N], pos[N];
bool vis[N];
set<int> s;
stack<int> st;
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < a[i - 1]) {
            flag = 0;
        }
    }
    if (flag) {
        for (int i = 1; i <= n; i++) {
            cnt[a[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            printf("%d ", cnt[i]);
        }
        return 0;
    }
    for (register int i = 1; i <= n; i++) {
        stack<int> st;
        for (register int j = i; j <= n; j++) {
            if (vis[a[j]]) {
                while (st.top() != a[j]) {
                    vis[st.top()] = 0;
                    st.pop();
                }
            } else {
                st.push(a[j]);
                vis[a[j]] = 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            vis[i] = 0;
        }
        while (!st.empty()) {
            cnt[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}
