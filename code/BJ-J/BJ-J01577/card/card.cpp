#include <iostream>
#include <stack>
using namespace std;
int a[500005], cnt[300005];
bool inst[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (inst[a[j]]) {
                while (true && !st.empty()) {
                    int u = st.top();
                    st.pop(), inst[u] = false;
                    if (u == a[j]) break;
                }
            }
            st.push(a[j]), inst[a[j]] = true;
        }
        while (!st.empty()) {
            int u = st.top();
            st.pop(), inst[u] = false;
            cnt[u]++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << " ";
    }
    return 0;
} // about 48
