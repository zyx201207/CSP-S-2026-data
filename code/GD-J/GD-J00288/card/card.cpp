#include<bits/stdc++.h>
 #define int long long
using namespace std;
const int maxn = 500005;
int a[maxn], id[maxn], ans[maxn], si[maxn], hd[maxn], to[maxn], nt[maxn], t;
// vector<int> v[maxn];
void add(int x, int y){
    t++;
    nt[t] = hd[x];
    to[t] = y;
    hd[x] = t;
}
void dfs(int x){
    si[x] = 1;
    // for(int i : v[x]){
    for(int j = hd[x];j;j = nt[j]){
        int i = to[j];
        dfs(i);
        si[x] += si[i];
    }
    ans[a[x]] += si[x];
}
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = n;i >= 1;i--){
        if(id[a[i]] == 0){
            // v[i + 1].push_back(i);
            add(i + 1, i);
            id[a[i]] = i;
        }else{
            // v[id[a[i]] + 1].push_back(i);
            add(id[a[i]] + 1, i);
        } 
    }
    dfs(n + 1);
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
