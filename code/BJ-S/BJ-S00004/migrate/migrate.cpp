#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e6 +9,M = 3e2 + 9;
ll a[N];
ll n,m;
int mn = 99999999,shu = 0;
void dfs(int now,int bu,int e){

    if(now == e){
        if(bu < mn){
            mn = bu;
            shu = 1;
            return ;
        }
        else if(bu == mn) shu++;
        return ;
    }
    for(int i = now + 1;i <= n;i++){
        if(a[i] - a[now] > m) break;
        dfs(i,bu + 1,e);
    }
    return ;
}
bool check(int x,int y){
    mn = 99999999,shu = 0;
    dfs(x,0,y);
    return(shu == 2);
}
void solved(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i + 3;j <= n;j++){
            if(check(i,j)) cnt++;
        }
    }
    cout << cnt << endl;
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t = 1;
    cin >> t >> t;
    while(t--){
        solved();
    }
    return 0;
}
