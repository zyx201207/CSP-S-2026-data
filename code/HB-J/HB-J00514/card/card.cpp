#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
bool vis[300005];
ll a[500005];
ll cnt[500005];
stack<int> st;
bool is_a = true;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1]) is_a = false;
    }
    if (is_a) {
        for (int i = 1; i <= n; i++) {
            cout << i << endl;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (vis[a[j]]) {
                while (!st.empty() && st.top() != a[j]) {
                    vis[st.top()] = false;
                    st.pop();
                }
                if (st.top() == a[j]) st.pop();
            }
            vis[a[j]] = true;
            st.push(a[j]);
        }
        while (!st.empty()) {
            cnt[st.top()]++;
            vis[st.top()] = false;
            st.pop();
        }
    }
    for (int j = 1; j <= m; j++) {
        cout << cnt[j] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}