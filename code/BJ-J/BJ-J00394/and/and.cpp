#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
long long a[200005];
void dfs(int x, int y, long long num){
    if(y >= m - 1){
        ans = max(ans, num & a[x]);
        return;
    }
    for(int i = x + 1; i < n; i++){
        dfs(i, y + 1, num & a[x]);
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        dfs(i, 0, a[i]);
    }
    cout << ans;
    return 0;
}
