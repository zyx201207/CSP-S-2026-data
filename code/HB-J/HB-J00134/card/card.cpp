// card
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 5e5 + 1023;
int n, m, a[N], ans[N], cnt[N], num[N], to[N];
bool vis[N];
stack<int> st, order;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // ++num[a[i]];
        // cnt[i] = num[a[i]];
    }
    // for (int i = 1; i <= m; ++i) num[i] = 0;
    for (int i = n; i >= 1; --i) {
        // if (num[a[i]] == 1) {
        //     while (st.top() != a[i]) {
        //         num[st.top()] = 0;
        //         st.pop();
        //     }
        // } else if (!vis[a[i]]) {
        //     if (!st.empty()) to[a[i]] = st.top();
        //     st.push(a[i]);
        //     // vector<int> s;
        //     // s.clear();
        //     // while (!st.empty()) {
        //     //     s.push_back(st.top());
        //     //     st.pop();
        //     // }
        //     // for (int j = s.size() - 1; j >= 0; --j) {
        //     //     st.push(s[j]);
        //     //     ans[s[j]] += cnt[i];
        //     // }
        //     vis[a[i]] = 1;
        //     num[a[i]] = 1;
        //     ans[a[i]] = cnt[i];
        //     order.push(a[i]);
        // }
        for (int j = 1; j <= m; ++j) num[j] = 0;
        while (!st.empty()) st.pop();
        for (int j = i; j <= n; ++j) {
            if (num[a[j]] == 1) {
                while (st.top() != a[j]) {
                    num[st.top()] = 0;
                    st.pop();
                }
            } else {
                num[a[j]] = 1;
                st.push(a[j]);
            }
        }
        while (!st.empty()) {
            ++ans[st.top()];
            st.pop();
        }
    }
    // while (!order.empty()) {
    //     int i = order.top();
    //     ans[to[i]] += ans[i];
    //     order.pop();
    // }
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
    return 0;
}
