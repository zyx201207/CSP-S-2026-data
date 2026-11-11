#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> p;
vector<vector<int>> g;
int n, m;
void dijsd(int i) {
    unordered_set<int> mp;
    for(;i < n;i++) {
        if(!mp.count(p[i])) {
            ans[p[i]]++;
            mp.insert(p[i]);
        }
        if(!g[i].empty()) {
            i = g[i].back();
        }
    }
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    g.resize(n);
    p.resize(n);
    ans.assign(m + 1, 0);
    unordered_map<int, int> mp;
    for(int i = 0;i < n;i++) {
        int a;
        cin >> a;
        p[i] = a;
        if(mp.count(a)) {
            g[mp[a]].push_back(i);
        } else {
            mp[a] = i;
        }
    }
    //for(int i = 0;i < n - 1;i++) g[i].push_back(i + 1);
    /*for(int v = 0;v < g.size();v++) {
        for(int i = 0;i < g[v].size();i++) cout << g[v][i] << ' ';
        cout << '\n';
    }*/
    for(int i = 0;i < n;i++) dijsd(i);
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
