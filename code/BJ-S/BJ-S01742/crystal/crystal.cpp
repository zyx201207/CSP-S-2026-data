#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c[3000005],maxx=-1;
ll pd(){
    ll t=c[2]-c[1];
    for(ll i=3;i<=n;i++){
        if(c[i]-c[i-1]!=t)return 0;
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    if(pd()){
        ll t=c[2]-c[1],ans=0,i=1;
        while(1){
            ans+=(t*i);
            if(ans>m)break;
            i++;
        }
        cout<<i;
        return 0;
    }
    for(ll i=n;i>0;i--){
        ll ans=0,k=m;
        for(ll j=i;c[i]-c[j]<=k&&c[j]!=0&&j>0;j--){
            k-=(c[i]-c[j]);
            ans++;
        }
        maxx=max(ans,maxx);
    }
    cout<<maxx;
    return 0;
}
