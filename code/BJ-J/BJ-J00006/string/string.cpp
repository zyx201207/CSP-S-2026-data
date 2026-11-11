#include<bits/stdc++.h>
using ll = long long;
//Ten years OI are none,dot't use long long can see your grandgrand...grand
using namespace std;
using pic = pair<ll,char>;
const ll N = 2e5 + 9;
pic a[N];
void solved(){
    ll n;
    cin >> n;
    string s;
    ll m = 0;
    for(ll i = 1;i <= n;i++){
        cin >> a[i].first >> a[i].second;
    }
    ll r = n;
    ll cnt = 0;
    for(ll i = 1;i <= r;i++){
        while(a[i].first > 0){
            if(a[i].second != a[r].second) cnt += min(a[i].first,a[r].first);
            if(a[i].first < a[r].first){
                a[r].first -= a[i].first;
                a[i].first = 0;
                break;
            }
            else{
                a[i].first -= a[r].first;
                r--;
            }
            if(i == r) break;
        }
    }
    cout << cnt << endl;
    return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll t = 1;
    //cin >> t;
    while(t--) solved();
    return 0;
}
