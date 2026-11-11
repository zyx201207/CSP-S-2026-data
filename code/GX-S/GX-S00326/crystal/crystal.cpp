#include<bits/stdc++.h>
#define rint long long
using namespace std;
const rint N=5e5+10,inf=0x3f3f3f3f;
rint n,m;
rint a[N];
rint s[N];
rint ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(rint i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=2;i<=n;i++){
        rint l=1,r=i-1,cnt=0;
        while(l<=r){
            rint mid=(l+r)>>1;
            rint k=a[i]*mid;
            if(k-s[i-1]+s[i-mid-1]<=m){
                cnt=mid;
                l=mid+1;
            }else r=mid-1;
        }
        ans=max(ans,cnt);
    }
    ans++;
    cout<<ans;
    return 0;
}
