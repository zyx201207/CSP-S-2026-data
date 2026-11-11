#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
string sa,sb;
ll L[200005],R[200005];
ll c[200005];
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;char y;
        scanf("%lld",&x);cin>>y;
        L[i]=R[i-1]+1;R[i]=L[i]+x-1;
        //printf("%lld %lld\n",L[i],R[i]);
        c[i]=(y-'a');
    }L[n+1]=R[n]+1;
    for(int i=1;i<=n;i++){
        //erfen zuoduandian
        ll l=1,r=n,x=R[n]-L[i]+1;
        ll zl,zr;
        while(l<r){
            ll mid=l+(r-l)/2;
            if(R[mid]>=x)r=mid;
            else l=mid+1;
        }
        //cout<<l<<endl;
        zl=l;
        l=1,r=n,x=R[n]-R[i]+1;
        while(l<r){
            ll mid=l+(r-l)/2;
            if(R[mid]>=x)r=mid;
            else l=mid+1;
        }
        zr=l;
        //cout<<i<<" "<<zl<<" "<<zr<<" "<<ans<<endl;
        if(zl==zr){
            if(c[i]!=c[zl])ans+=(R[i]-L[i]+1);
            continue;
        }
        if(c[i]!=c[zl]){
            ans+=((R[n]-L[i]+1)-L[zl]+1);
        }
        if(c[i]!=c[zr]){
            ans+=(R[zr]-(R[n]-R[i]+1)+1);
        }
        for(int j=zr+1;j<=zl-1;j++){
            if(c[i]!=c[j]){
                ans+=(R[j]-L[j]+1);
            }
        }
       // cout<<ans<<endl;
    }
    cout<</*ans<<" "<<*/ans/2<<endl;

    return 0;
}
