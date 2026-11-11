#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],maxn=-0x3f3f3f3f3f3f3f3f;
bool f(int x){
    for(int i=x;i<=n;i++){
        if(a[i]*x-(sum[i]-sum[i-x])<=m&&(a[i]*x)-(sum[i]-sum[i-x])>=0){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(f(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
