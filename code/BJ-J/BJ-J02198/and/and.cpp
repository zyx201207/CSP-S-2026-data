#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool book[200005];
long long maxn = -1;
int n, m, bb;
void dfs(int step, long long sum){
    if(step == m){
        maxn = max(maxn, sum);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(book[i] == 0){
            book[i] = 1;
            dfs(step + 1, sum & a[i]);
            book[i] = 0;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        dfs(0, a[i]);
    }
    cout << maxn;
    return 0;
}