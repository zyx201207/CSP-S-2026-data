#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,a[N],m,t[N],dis[N],sum[N],ss[N];
bool check(int x){
    for(int i=x;i<=n;i++){
        int p=a[i]*(x-1)-(sum[i-1]-sum[i-x]);
        if(p<=m)return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,mid,ans=0;
    while ((l<=r)){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;ans=mid;
        }else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}