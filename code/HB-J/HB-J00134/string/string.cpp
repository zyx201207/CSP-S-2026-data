// string
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 1023;
int n, a[N];
char c[N];
long long l, ans;

struct Node {
    long long a;
    char c;
    Node() {}
    Node(long long a, char c) : a(a), c(c) {}
};

vector<Node> st, ed;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        l += a[i];
    }
    long long midl = l / 2, midr = l - midl + 1, len = 0;
    st.push_back(Node{0, '0'});
    for (int i = 1; i <= n; ++i) {
        if (len + 1 <= midl && midr <= len + a[i]) {
            st.push_back(Node(midl - len, c[i]));
            ed.push_back(Node(len + a[i] - midr + 1, c[i]));
        } else if (len + a[i] < midr) {
            st.push_back(Node(min(len + a[i], midl) - len, c[i]));
        } else {
            ed.push_back(Node(len + a[i] - max(len + 1, midr) + 1, c[i]));
        }
        len += a[i];
    }
    ed.push_back(Node{0, '0'});
    for (int i = 1; i < st.size(); ++i) st[i].a += st[i - 1].a;
    reverse(ed.begin(), ed.end());
    int m = ed.size();
    for (int i = 1; i < m; ++i) ed[i].a += ed[i - 1].a;
    for (int i = 1, j = 1; i < st.size(); ++i) {
        if (ed[j].c != st[i].c) {
            long long ql = max(ed[j - 1].a + 1, st[i - 1].a + 1);
            long long qr = min(ed[j].a, st[i].a);
            ans += qr - ql + 1;
        }
        while (j + 1 < m && ed[j].a + 1 <= st[i].a) {
            ++j;
            if (ed[j].c != st[i].c) {
                long long ql = max(ed[j - 1].a + 1, st[i - 1].a + 1);
                long long qr = min(ed[j].a, st[i].a);
                ans += qr - ql + 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
