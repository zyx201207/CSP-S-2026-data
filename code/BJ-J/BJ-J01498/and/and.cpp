#include <bits/stdc++.h>
using namespace std;
long long n , m , ans = 0;
vector<long long> a(n + 1);
void dfs(long long u , long long sum , long long v){
    if(u >= n + 1 || v >= m + 1) {
        if(v < m) return ;
        ans = max(sum , ans);
        return ;
    }
    dfs(u + 1 , sum , v);
    dfs(u + 1 , sum & a[u] , v + 1);
    return ;
}
int main(){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(long long i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    for(long long i = 1;i <= n;i ++){
        dfs(i , a[i], 0);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
