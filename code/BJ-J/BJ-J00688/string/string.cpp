#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
ll a[MAXN];
char k[MAXN];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n;
    cin >>n;
    ll maxn=0;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        cin >> k[i];
        maxn+=a[i];
    }
    ll pos=0, ans=0;
    for(ll i=1, j=n;pos<=maxn/2;){
        // cout << i << " " << j << endl;
        if(k[i]!=k[j]){
            ans+=min(a[i], a[j]);
        }
        pos+=min(a[i], a[j]);
        ll minn=min(a[i], a[j]);
        a[i]-=minn;
        a[j]-=minn;
        if(a[i]==a[j]){
            i++, j--;
        }
        else if(a[i]==0){
            i++;
        }
        else{
            j--;
        }
    }
    cout << ans;
}