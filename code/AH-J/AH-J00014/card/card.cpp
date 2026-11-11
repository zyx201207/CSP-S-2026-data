#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int cnt[300005];
int a[500005];
int lst[300005], In[300005];
int n, m;
vector<int> g[300005];
void Tops_sort() {
    queue<int> q;
    for (int i = 1; i <= m; ++ i) {
        if (!In[i]) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int h = q.front(); q.pop();
        for (int i = 0; i < g[h].size(); ++ i) {
            int to = g[h][i];
            cnt[to] += cnt[h];
            -- In[to];
            if (!In[to]) q.push(to);
        }
    }
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    faster;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        ++ cnt[a[i]], lst[a[i]] = i;
    }
    for (int i = 1; i <= m; ++ i) {
        if(lst[i]==n)continue;
        g[i].push_back(a[lst[i]+1]);
        In[a[lst[i]+1]]++;
    }
    Tops_sort();
    for (int i = 1; i <= m; ++ i) cout << cnt[i] << ' '; cout << '\n';
    return 0;
}//made_by_zap2727
