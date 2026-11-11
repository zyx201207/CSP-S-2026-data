#include <bits/stdc++.h>

#define ll long long
#define AC return 0
#define pb push_back
#define pp pop_back
#define db double
#define max(a , b) a > b ? a : b

const int N = 2e5 + 5;

ll n , m , a[N] , ma;

void dfs(ll x , ll sum , ll ans){
    if (sum > m){
        return ;
    }
    if (x == n + 1){
        if (ans != 1073741824){
            ma = max(ma , ans);
        }
        return ;
    }
    dfs(x + 1 , sum + 1 , ans & a[x]);
    dfs(x + 1 , sum , ans);
}

using namespace std;

int main(){
//    freopen("and.in" , "r" , stdin);
//    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1 , 0 , 1073741824);
    cout << ma;
    AC;
}
/**
1073741824‬
*/
