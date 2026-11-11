#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

constexpr int maxn = 5e5 + 5, maxm = 3e5 + 5;

int n, m, a[maxn], cnt[maxn];
bool last[maxm];
stack<int> st;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (last[a[j]]) while (st.top() != a[j]) last[st.top()] = false, st.pop();
            else st.push(a[j]), last[a[j]] = true;
        }
        while (st.size()) cnt[st.top()]++, st.pop();
        memset(last, 0, sizeof last);
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}
