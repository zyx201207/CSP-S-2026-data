#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[200005];
    char b[200005][3];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    ll l = 1;
    ll r = n;
    ll ans = 0;
    while(l < r){
        if(a[l] < a[r]){
            if(b[l][0] != b[r][0]){
                ans = ans + a[l];
            }
            a[r] = a[r] - a[l];
            l++;
        }
        else if(a[l] > a[r]){
            if(b[l][0] != b[r][0]){
                ans = ans + a[r];
            }
            a[l] = a[l] - a[r];
            r--;
        }
        else{
            if(b[l][0] != b[r][0]){
                ans = ans + a[r];
            }
            l++;
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
