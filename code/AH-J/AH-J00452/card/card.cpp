#include <cstdio>
#include <bitset>
#include <stack>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
using namespace std;
bitset<300010> in_stack;
int a[500010];
int ans[500010];
int n, m;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	rep (i, 1, n) scanf("%d", &a[i]);
	stack<int> st;
	per (i, n, 1) {
		if (!in_stack[a[i]]) {
			in_stack[a[i]] = true;
			st.push(a[i]);
		}
		else {
			while (st.top() != a[i]) {
				in_stack[st.top()] = false;
				st.pop();
			}
		}
		rep (j, 1, m) ans[j] += in_stack[j];
	}
	rep (i, 1, m) printf("%d ", ans[i]);
    return 0;
}
