#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
ll m,ans=INT_MIN,mx[500005],a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        s[i]=a[i]+s[i-1];
        mx[i]=max(mx[i-1],a[i]);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(mx[j]*(j-i+1)<=s[j]-s[i-1]+m){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout << ans;
    return 0;
}
