
#include <iostream>
#include <stack>

using namespace std;

int n = 0;
int m = 0;
int a[500009] = {};
int res[300009] = {};

void Out (int x) {

    stack<int> st;
    int t[300009] = {};
    for (int i = x; i <= n; i++) {
        if (t[a[i]] == 0) {
            st.push(a[i]);
            t[a[i]] = 1;
        }
        else {
            //pop
            while (st.top() != a[i]) {
                t[st.top()] = 0;
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        res[st.top()]++;
        st.pop();
    }
}

int main () {

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        Out(i);
    }

    for (int i = 1; i <= m; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
