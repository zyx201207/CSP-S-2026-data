#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s[500005],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n;i>=1;i--){
        int l=1,r=i;
        while(r-l>5){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid;
        }
        for(int j=l;j<=r;j++)
            if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m) ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}