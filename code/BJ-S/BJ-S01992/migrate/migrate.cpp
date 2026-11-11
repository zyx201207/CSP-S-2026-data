#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010] , flag[2000010];
void dfs(int x , int y , int m , int f , int dep){
    if(f >= y){
        flag[dep]++;
        return;
    }
    int dd = 0;
    for(int i = f + 1;dd <= m && f <= y;i++){
        dd += a[i] - a[i - 1];
        dfs(x , y , m , i , dep + 1);
    }
}
bool check(int x , int y , int m){
    memset(flag , 0 , sizeof(flag));
    int f = a[y] - a[x];
    if(f <= m) return false;
    dfs(x , y , m , x , 1); 
    int g;
    for(int i = 1;i <= 10000;i++){
        if(flag[i] != 0){
            g = i;
            break;
        }
    }    
    if(flag[g] == 2){
        return true;
    }
    else return false;
}
void solve(){
    memset(a , 0 , sizeof(a));
    int n , m , ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(check(i , j , m)){
                ans++;
            }
        }                
    }
    cout << ans << endl;
}
signed main(){  
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int cc , T;
    cin >> cc >> T;
    while(T--){
        solve();
    }
    return 0;
}
