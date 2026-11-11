#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[1000005],a[1000005],ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
