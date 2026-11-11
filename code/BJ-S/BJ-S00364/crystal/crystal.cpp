#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll pre[500005];
int n;
ll m;
bool ch(ll x,ll jz){
    ll js=(a[n]-a[jz])*(jz-x+1);
    if((pre[jz]-pre[x-1])-js<=m){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
       // cout<<i<<" "<<a[i]<<'\n';
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+(a[n]-a[i]);
       //cout<<i<<" "<<pre[i]<<'\n';
    }
    //int x,jz;
    //cin>>x>>jz;
    //cout<<ch(x,jz);
   // return 0;
   //
    ll Max=0;
    for(int i=1;i<=n;i++){
        ll l=1,r=i,ans;
        while(l<=r){
            int mid=(l+r)/2;
            if(ch(mid,i)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        //cout<<i<<" "<<ans<<'\n';
        Max=max(Max,i-ans+1);
    }
    //cout<<'\n';
    cout<<Max;
    return 0;
}
