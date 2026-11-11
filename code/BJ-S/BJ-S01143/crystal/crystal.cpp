#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll n,m;
bool chk(int x){
    ll minn=4e18;
    for(int i=1;i<=n-x+1;i++){
        ll sum=0;
        int l=i,r=i+x-1;
        int mid=(l+r)/2;
        for(int j=l;j<=mid;j++)sum+=a[r-j+l]-a[j];
        minn=min(minn,sum);
    }
    return minn<=m;
}
bool chk1(){
    if(n==1)return true;
    ll x=a[2]-a[1];
    for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=x)return false;
    return true;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    if(chk1()){
        if(n==1)cout<<1;
        else{
            ll x=a[2]-a[1];
            ll y=m/x;
            for(ll i=1;i<=n;i++){
                if((i*i-(i&1))/4>y){
                    cout<<i-1;
                    return 0;
                }
            }
            cout<<n;
        }
        return 0;
    }
    int l=1,r=n;
    int ans=1;
    while(l<=r){
        int mid=(l+r)/2;
        if(chk(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}