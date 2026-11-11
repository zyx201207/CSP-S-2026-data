#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxx,minn=10000000000000,xt[500005],ans=1;
ll a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        if(b[i]<minn){
            minn=b[i];
            xt[0]=i;
        }
    }
    for(ll i=2;i<=n;i++){
        if(b[i]==minn){
            xt[ans++]=i;
        }
    }
    for(ll i=1;i<ans;i++){
        ll w=m,cnt=1;
        for(ll j=0;xt[i]-j>=2&&w>=0;j++){
            w-=b[xt[i]-j];
            if(w<0)break;
            cnt++;
        }
        maxx=max(maxx,cnt);
        w=m,cnt=1;
        for(ll j=0;xt[i]+j<=n&&w>=0;j++){
            w-=b[xt[i]+j];
            if(w<0)break;
            cnt++;
        }
        maxx=max(maxx,cnt);
    }
    cout<<maxx;
    return 0;
}
