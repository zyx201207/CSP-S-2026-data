#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans, num;
void solve(int cur, int last){
    if(cur > m){
        if(num > ans) ans = num;
        return;
    }
    for(int i=last+1; i<=n+cur-m; i++){
        if(cur == 1){
            num = a[i];
            solve(cur + 1, i);
        }
        else{
            int t = num;
            num &= a[i];
            solve(cur + 1, i);
            num = t;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    solve(1, 0);
    cout << ans;
    return 0;
}
