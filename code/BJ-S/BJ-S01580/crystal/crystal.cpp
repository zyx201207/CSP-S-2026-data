#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010],b[500010],c[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f1=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)f1=0;
    }

    sort(a+1,a+1+n);
    int f2=1;
    ll kl=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(i>2&&a[i]-a[i-1]!=kl) f2=0;
        c[i]=c[i-1]+a[i];
        //cout<<c[i]<<" ";
    }
    //cout<<endl;
    ll ans=0;
    if(f1||f2){
        for(ll i=2;i<=n;i++){
            b[i]=(i-1)*a[n]-c[n-1]+c[n-i];
        }
        ll l=1,r=n;
        while(l<=r){
            ll mid=(l+r)/2;
            if(b[mid]<=m){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }else{
        ll l=2,r=n;
        while(l<=r){
            ll mid=(l+r)/2;

            ll awa=1e18;
            if(mid==1){
                awa=1;
            }
            else{
                for(ll j=mid;j<=n;j++){
                    awa=min(awa,(mid-1)*a[j]-c[j-1]+c[j-mid]);
                    //cout<<(mid-1)*a[j]-c[j-1]+c[j-mid]<<" ";
                }

            }

            if(awa<=m){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }

    /*
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    */

    cout<<ans;
    return 0;
}
