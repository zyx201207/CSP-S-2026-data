//100pts
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],cnt[500005];
inline bool check(int x){
    bool flag=false;
    for(int i=1;i+x-1<=n;i++){
        if(a[i+x-1]*x-cnt[i+x-1]+cnt[i-1]<=m) flag=true;
    }return flag;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+a[i];
    int l=1ll,r=n,mid,ans=1ll;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1ll;
        else r=mid-1ll;
    }cout<<ans;
    return 0;
}