#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],minn,d[1000010],sum[1000010],su[1000010];
bool check(long long k){
    minn=0x3f3f3f3f+1;
    for(int i=n-1;i>=1;i--){
        sum[i]=sum[i+1]+su[i+1]-sum[i+k-1]-su[i+k]*(k-1)+sum[i+k]+su[i+k+1]*(k-1);
        if(i+k-1>n)continue;
        if(minn==0x3f3f3f3f+1)minn=sum[i];
        else minn=min(sum[i],minn);
    }
    return minn<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }for(int i=n;i>=1;i--){
        su[i]=su[i+1]+d[i];
    }
    long long l=1,r=n,ans=-0x3f3f3f3f,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }cout<<ans;
    return 0;
}
