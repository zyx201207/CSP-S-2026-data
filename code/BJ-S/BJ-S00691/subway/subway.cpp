#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> w;
set<int> ed;
vector<vector<int>> v;
vector<vector<bool>> b;
vector<vector<int>> cn;
int ans = 1e9 + 10;
void f(int cnt, int qishi, int zhongzhi) {
    if (qishi = zhongzhi) {
        cnt += (w[zhongzhi]);
        ans = min(ans, cnt);
        return;
    }
    if (ed.find(qishi) != ed.end())return;
    for (int i = 0; i < n; i ++) {
        for(int j = 1; j < v[i].size(); j += 2) {
            if (!b[i][j])continue;
            if (v[i][j] == qishi) {
                b[i][j] = false;
                cnt += w[i];
                f(cnt,qishi++,zhongzhi);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    w.resize(m);
    for (int i = 0; i < m; i ++)cin >> w[i];
    for (int i = 0; i < n; i ++) {
        int k;
        cin >> k;
        v.resize(n,vector<int>(2 * k + 2));
        b.resize(n,vector<bool>(2 * k + 2));
        v[i][0] = k;
        for(int j = 1; j <= 2 * k; j ++) {
            cin >> v[i][j];
        }
        ed.insert(v[i][2 * k]);
    }
    cn.resize(q, vector<int> (2));
    for (int i = 0; i < q; i ++) {
        cin >> cn[i][0] >> cn[i][1];
        ans = 0;
        int cnt = 0;
        f(cnt, cn[i][0], cn[i][1]);
        cout << ans << endl;
    }
    return 0;
}
