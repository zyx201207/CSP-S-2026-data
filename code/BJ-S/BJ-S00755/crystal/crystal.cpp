#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010];
inline bool check(int mid){
    int cur=a[mid]*mid-sum[mid];
    for(int l=2;l+mid-1<=n;l++){
        int r=l+mid-1;
        cur=min(cur,a[r]*mid-sum[r]+sum[l-1]);
    }
    return cur<=m;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    sum[0]=0;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=0,r=n,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
