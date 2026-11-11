#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,s[500005];
int query(int x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)>>1;
        if((x-mid+1)*a[x]-s[x]+s[mid-1]<=m)r=mid;
        else l=mid+1;
    }
    return x-l+1;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=2;i<=n;i++)ans=max(query(i),ans);
    cout<<ans;
    return 0;
}