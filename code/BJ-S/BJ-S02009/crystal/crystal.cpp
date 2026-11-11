#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],l,r,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    l=1;
    r=1;
    while(l<=n&&r<=n){
        if(a[r]*(r-l+1)-m>s[r]-s[l-1]){
            l++;
        }else{
            r++;
        }
        if(a[r]*(r-l+1)-m<=s[r]-s[l-1]){
            ans=max(ans,r-l+1);
        }
        while(r<l){
            r++;
        }
        // cout<<a[r]*(r-l+1)<<" "<<s[r]-s[l-1]<<"\n";
        // cout<<l<<" "<<r<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
    //tt520
}