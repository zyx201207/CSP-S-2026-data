#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
ll n, m;
ll a[maxn];
ll sum[maxn], sum1[maxn];

int main(){
    freopen("crystal.in","r", stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    for(int i = n; i >= 1; i --){
        sum[i] = a[i] - a[i-1];
    }
    //for(int i = 1; i <= n; i ++){
     //   cout << sum[i] << " ";
    //}
    for(int i = 2; i <= n; i ++){
        sum1[i] = sum1[i-1] + sum[i];
    }
    ll cnt = 0, ans = 1,f = 1, fl = 0, f2 = 0;
    for(int i = 2; i <= n; i ++){

        if(sum[i]*ans + cnt <= m){
            cnt += sum[i]*ans;
            ans ++;
            if(fl == 1){
                f2 = 1;
            }
        }else{
            cnt = cnt-(sum1[i] - sum1[f-1])+sum[i]* ans;
            f ++;
            fl = 1;
        }
        //cout << cnt <<" ";
    }
    cout << ans-f2;
    return 0;
}
