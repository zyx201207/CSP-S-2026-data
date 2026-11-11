#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
pair<ll, char> a[200005];

ll solve(){
    ll cnt = 0;
    for(int i=1, j=n; i<j;){
        if(a[i].second != a[j].second){
            if(a[i].first == a[j].first){
                cnt += a[i].first, i++, j--;
            }
            else if(a[i].first>a[j].first){
                cnt += a[j].first, a[i].first -= a[j].first, j--;
            }
            else if(a[i].first<a[j].first){
                cnt += a[i].first, a[j].first -= a[i].first, i++;
            }
        }
        else{
            if(a[i].first == a[j].first){
                i++, j--;
            }
            else if(a[i].first>a[j].first){
                a[i].first -= a[j].first, j--;
            }
            else if(a[i].first<a[j].first){
                a[j].first -= a[i].first, i++;
            }
        }
    }
    return cnt;
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(ll i=1; i<=n; i++){
        cin>>a[i].first>>a[i].second;
    }
    cout<<solve();
    return 0;
}
