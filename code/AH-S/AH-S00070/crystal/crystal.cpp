#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans=1,f[500005];
int Find(int i){
    int l=1,r=i;
    while(l<r){
        int mid=l+r>>1;
        if((i-mid)*a[i]-f[i-1]+f[mid-1]<=m) r=mid;
        else l=mid+1;
    }
    return l;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
    for(int i=1;i<=n;i++)
        ans=max(ans,i-Find(i)+1);
    cout<<ans;
    return 0;
}
