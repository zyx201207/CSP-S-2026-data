#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("card.in", r, stdin);
    freopen("card.out", w, stdout);
    vector<int> v, ans;
    int n, m;
    int cnt[105];
    bool flag = false;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        ans.clear();
        for (int j = i; j <= n; j++) {
            for (int k = 0; k < ans.size(); k++) {
                if (v[k] == v[j]) flag = true;
                if (flag == true) ans.erase(v.begin() + k);
            }
            ans.push_back(v[j]);
        }
        for (int k = 0; k < ans.size(); k++)
            cnt[ans[k]]++;
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
    return 0;
}
