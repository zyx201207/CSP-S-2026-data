#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define file(a) \
(freopen(#a".in", "r", stdin),\
freopen(#a".out", "w", stdout))
const int N = 5e5+5, M = 3e5+5;
int n, m, a[N], cnt[M], last[M], to[M], ans[M];
vector<int> from[N];

stack<int> p1, p2;
void dfs(){
    p1.push(0);
    while(!p1.empty()){
        const int u = p1.top();
        p1.pop();
        ans[u] = cnt[u];
        p2.push(u);
        for(const int &v : from[u])
            p1.push(v);
    }
    while(!p2.empty()){
        const int u = p2.top();
        p2.pop();
        for(const int &v : from[u])
            ans[u] += ans[v];
    }
}

int main(){
    ios::sync_with_stdio(false);
    file(card);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ++cnt[a[i]];
        last[a[i]] = i;
    }
    for(int i = 1; i <= m; ++i){
        to[i] = a[last[i] + 1];
        from[to[i]].push_back(i);
    }
    dfs();
    for(int i = 1; i <= m; ++i)
        cout << ans[i] << ' ';
    return 0;
}
