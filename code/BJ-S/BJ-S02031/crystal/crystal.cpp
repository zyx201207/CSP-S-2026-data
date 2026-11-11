#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
const int N = 5e5+9 ;
ll n,m ;
ll a[N] ;
ll sum[N] ;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a[i] ;
    }
    int ans = -1;
    sort(a+1,a+n+1);
    for(int i = 1; i <= n ; i ++ ){
        sum[i] = sum[i-1] + (a[i]-a[i-1])*(i-1) ;
    }
    for(int i = 2 ; i <= n ; i ++ ){
        int cnt = 0;
        int l = 0 , r = i ;
        while(l <= r){
            int mid = (l+r)/2 ;
            ll need = sum[i] - (a[i]-a[mid])*(mid-1) - sum[mid] ;
            if(need <= m){
                r = mid -1 ;
                cnt = max(cnt,i-mid+1);
            }
            else{
                l = mid + 1 ;
            }
        }
        ans = max(ans , cnt) ;
    }
    cout << ans ;
    return 0;
}
// for my love!