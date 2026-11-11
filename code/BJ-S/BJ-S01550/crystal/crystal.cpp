#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    bool flag1 = 1,flag2 = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i] ;
        if(a[i] != i){
            flag2 = 0;
        }
    }
    sort(a+1,a+n+1);
    ll d = a[2]-a[1];
    for(int i = 3; i <= n; i++){
        if(a[i]-a[i-1] != d){
            flag1 = 0;
        }
    }
    if(flag1 || flag2){
        ll d = a[2]-a[1];
        ll sum = 0,cnt = 0;
        for(int i = 0; i < n; i++){
            if(sum+d*i <= m){
                sum += d*i;
                cnt++;
            }
        }
        cout << cnt ;
    }
    else{
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                c[j] = a[i]-a[j];
            }
            sort(c+1,c+n+1);
            ll sum = 0,cnt = 0;
            for(int i = 1; i <= n; i++){
                if(c[i] < 0){
                    continue;
                }
                if(sum + c[i] <= m){
                    sum += c[i];
                    cnt++;
                }
                else{
                    break;
                }
            }
            ans = max(ans,cnt);
        }
        cout << ans ;
    }
    return 0;
}
