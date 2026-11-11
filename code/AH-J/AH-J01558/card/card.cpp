#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], cnt[N], p[N], ans[N];
vector<int> v[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    v[a[n]].push_back(a[n]);
    p[a[n]] = 1;
    for(int i=n-1; i>=1; i--){
        if(p[a[i]] == 1) continue;
        for(int j=0; j<v[a[i + 1]].size(); j++){
            v[a[i]].push_back(v[a[i + 1]][j]);
        }
        v[a[i]].push_back(a[i]);
        p[a[i]] = 1;
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<v[i].size(); j++){
            ans[v[i][j]] += cnt[i];
        }
    }
    for(int i=1; i<=m; i++) cout << ans[i] << " ";
    return 0;
}
