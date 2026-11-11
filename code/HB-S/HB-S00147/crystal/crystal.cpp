#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+1;
int n, ans;
ll m, a[N];
void sol1(){
    for (int i = 1; i <= n; i+=1) cin >> a[i];
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i+=1){
        int cnt = 1;
        ll kp = 0;
        for (int j = i-1; j >= 1; j-=1){
            if (a[i]-a[j]+kp > m) break;
            cnt++;
            kp += a[i]-a[j];
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return ;
}
void sol2(){
    ans = 1;
    ll kp = 0;
    for (int i = 2; i <= n; i += 1){
        if (kp+((a[i]-a[i-1])*(i-1)) > m) break;
        else {
            ans += 1;
            kp += ((a[i]-a[i-1])*(i-1));
        }
    }
    cout << ans;
}
int g[202];
void sol3(){
    for (int i = 1; i <= n; i+=1) {
        cin >> a[i];
        g[a[i]+100]+=1;
    }
    for (int i = 0; i <= 200; i+=1){
        int res = g[i];
        ll s = 0;
        for (int j = 1; j <= 200; j+=1){
            if (i-j >= 0){
                if ((g[i-j]*j)+s > m){
                    res += ((m-s)/j);
                    break;
                }
                else{
                    res += g[i-j];
                    s += g[i-j]*j;
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans;
    return ;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (n <= 5000) sol1();
    else if (m <= 1e8) sol3();
    else sol2();
    return 0;
}
