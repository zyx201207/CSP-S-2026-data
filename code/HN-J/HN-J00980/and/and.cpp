#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 9;

ll n, m, ans = 0, a[N];

void dfs(int x, ll w, int s){
    if(s == m){
        ans = max(ans, w);
        return ;
    }
    if(x > n){
        return ;
    }

    dfs(x + 1, w & a[x], s + 1);
    dfs(x + 1, w, s);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        dfs(i + 1, a[i], 1);
    }
    cout << ans;
    return 0;
}
