#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, k, maxa = -1;
int a[N];
stack<int> v;

int calc() {
    int ans = v.top();
    stack<int>st = v;
    while (!st.empty()) {
        ans &= st.top();
        st.pop();
    }
    return ans;
}

int dfs(int x) {
    if (k == m) {
        int res = calc();
        return res;
    }

    if (m - k == n - x + 1) {
        v.push(a[x]);
        k++;
        int re = dfs(x + 1);
        v.pop();
        k--;
        return re;
    }
    else {
        int ret1 = dfs(x + 1);

        v.push(a[x]);
        k++;
        int ret2 = dfs(x + 1);
        v.pop();
        k--;

        return max(ret1, ret2);
    }
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >>n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= maxa) {
            maxa = a[i];
        }
    }

    if (m == 1) {
        cout << maxa;
        return 0;
    }

    if (m == n) {
        int ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans &= a[i];
        }

        cout << ans;

        return 0;
    }

    cout << dfs(1);
    return 0;
}
