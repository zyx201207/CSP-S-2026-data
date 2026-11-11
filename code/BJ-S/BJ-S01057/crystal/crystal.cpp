#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[666666];
ll s[666666];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l = 1,r = 0;
    int ans = 0;
    while(l<=n){
        int k = r+1;
        ll sss = 1ll*a[k]*(k-l+1)-s[k]+s[l-1];
        while(r<=n&&sss<=m){
            r++;
            k = r+1;
            sss = 1ll*a[k]*(k-l+1)-s[k]+s[l-1];
        }
        ans = max(ans,r-l+1);
        l++;
    }
    cout<<ans;
    return 0;
}
