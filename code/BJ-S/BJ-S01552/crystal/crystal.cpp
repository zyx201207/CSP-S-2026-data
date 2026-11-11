#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,a[500010],w[500010],dp[500010],ans,val;

bool check(ll cnt){
    for(int k = 1;k <= n;k++){
        val = a[k];
        ll c = 0,sum = 0;
        for(int i = 1;i <= k;i++){
            if(sum + val-a[i] <= m){
                sum += val-a[i];
                c++;
            }
        }
        if(c >= cnt)return 1;
    }
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n <= 5000){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        ll l = 1,r = n,mid;
        while(l <= r){
            mid = (l+r)>>1;
            if(check(mid)){
                l = mid+1;
            }
            else r = mid-1;
            //cout << l <<" "<<r <<" \n";
        }
        cout << r;
    }
    else{
        bool flag = 1,flag2 = 1;
        for(int i = 1;i <= n;i++){
            if(a[i] >= 100) flag = 0;
            if(i == 1)continue;
            if(i == n)continue;
            if(a[i] - a[i-1] != a[i+1]-a[i])flag2 = 0;
        }
        flag = 0;
        if(flag){
            for(int k = -100;k <= 100;k++){
                for(int j = 1;j <= n;j++){
                    w[j] = (k - a[j] < 0) ? 1e9 : (k-a[j]);
                }
                memset(dp,0,sizeof dp);
                for(int i = 1;i <= n;i++){
                    for(int j = m;j >= w[i];j--){
                        dp[j] = max(dp[j],dp[j-w[i]]+1);
                    }
                }
                ans = max(ans,dp[m]);
            }
            cout << ans;
        }
        else if(flag2){
            ll cha = a[n]-a[n-1];
            int i;
            for(i = 1;i <= n+1;i++){
                if(1ll*(1ll*cha+cha*i)*((1ll*cha*i-cha)/cha+1)/2 > m)break;
            }
            cout << i-1;
        }
    }
    return 0;
}
