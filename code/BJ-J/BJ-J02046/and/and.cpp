#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n, m;
ll a[N];
ll ans;
void dfs(int u, ll cnt, int i){
    if(u == m){
        //cout <<cnt << " ";
        ans = max(ans, cnt);
    }
    if(i == n){
        return ;
    }
    dfs(u+1, cnt & a[i], i+1);
    dfs(u, cnt, i+1);

}
void ans1(){
    ans = (1 << 31)-1;
    for(int i=1; i<=n; i++){
        ans &= a[i];
    }
    cout <<ans;
}
void ans2(){
    ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, a[i]);
    }
    cout << ans;
}
void ans3(){
    for(int i=1; i<=n; i++){
            ll maxn = 1 << 31;
            maxn -= 1;
        for(int j=1; j<=n; j++){
            if(j == i)continue ;
            maxn &= a[j];
        }
        ans = max(ans, maxn);
    }
    cout << ans;
}
void ans4(){
    dfs(0, (1 << 31)-1, 1);
    cout << ans;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n == m){
        ans1();
    }else if(m == 1){
        ans2();
    }else if(m == n-1){
        ans3();
    }else{
        //cout << "???";
        ans4();
    }
    return 0;
}
