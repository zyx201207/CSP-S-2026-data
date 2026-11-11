#include <bits/stdc++.h>
using namespace std ;
const int maxn = 2e5+5 ;
int box[maxn] ;
int a[maxn] ;
int n , m ;
int ans = -1 ;
void dfs(int cur){
    if (cur > m){
        int sum = a[box[1]] ;
        for (int i = 2 ; i <= m ; i ++) sum = sum & a[box[i]] ;
        ans = max(ans,sum) ;
        return ;
    }
    for (int i = box[cur-1] + 1 ; i <= n ; i ++){
        box[cur] = i ;
        dfs(cur+1) ;
    }
}
int main (){
    freopen("and.in","r",stdin)  ;
    freopen("and.out","w",stdout);
    cin >> n >> m ;
    for (int i = 1 ; i <= n ; i ++){
        cin >> a[i] ;
    }
    dfs(1) ;
    cout << ans ;
    return 0 ;
}
