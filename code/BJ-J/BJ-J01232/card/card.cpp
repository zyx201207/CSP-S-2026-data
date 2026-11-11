#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m,a[500005],cnt[300005];
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(ll i = 1;i <= n;i++){
        ll b[n - i + 1];
        for(ll j = i;j <= n;j++){
            b[j] = a[j];
            for(ll k = 1;k < j;k++){
                if(b[k] == b[j]){
                    for(ll l = 1;l < j;l++){
                        b[l] = 0;
                    }break;
                }
            }
        }ll j = 1;
        while(b[j]){
            cnt[b[j++]]++;
        }
    }for(ll i = 1;i <= m;i++) cout << cnt[i] << ' ';
return 0;
}