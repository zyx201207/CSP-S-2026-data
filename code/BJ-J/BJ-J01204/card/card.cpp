#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int ans[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n, m, a[N];
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> q;
    for(int i = 1; i <= n; i++) {
        q.clear();
        for(int j = i; j <= n; j++) {
            for(int k = 0; k < q.size(); k++) {
                if(q[k] == a[j]) {
                    for(int l = 1; l <= q.size() - k + 1; l++) {
                        q.pop_back();
                    }
                    break;
                }
            }
            q.push_back(a[j]);
        }
        for(int j : q){
            ans[j]++;
        }
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
