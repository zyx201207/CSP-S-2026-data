#include <bits/stdc++.h>
using namespace std;

int main(){
#define int long long
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    // freopen(argv[1], "r", stdin);
    // freopen(argv[2], "w", stdout);

    int n, m; scanf("%lld %lld", &n, &m);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        // printf("%lld", i);
    }

    vector<int> ans(m + 1, 0);
    for(int i = 1; i <= n; i++) {
        // cout << i << endl;
        stack<int> f;
        vector<int> app(m + 1, false);
        for(int j = i; j <= n; j++) {
            // cout << j << endl;
            // if(app[a[j]]) {
                while(app[a[j]] && !f.empty()) {
                    app[f.top()] = false;
                    f.pop();
                }
            // }
            app[a[j]] = true;
            f.push(a[j]);
            // cout << "e" << endl;
        }

        for(int j = 1; j <= m; j++) ans[j] += app[j];
        // cout << "e" << endl;
    }

    for(int i = 1; i <= m; i++) printf("%lld ", ans[i]);
}
