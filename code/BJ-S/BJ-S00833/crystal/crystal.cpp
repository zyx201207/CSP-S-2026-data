#include<bits/stdc++.h>
#define ll long long
using namespace std;
//I CAN AK (C C F)CSP
ll n,m,a[500010];
bool ck(long long x){
    if(x<1){
        return 0;
    }
    return 1;
}
ll solve(ll i){
    ll now=i;
    ll caozo=m;
    ll cnt=0;
    while(ck(now)){
        caozo-=a[i]-a[now];;
        if(caozo>-1&&ck(now)){
            //cout<<(caozo>=0&&ck(now))<<' '<<caozo<<' '<<now<<' '<<(caozo>=0)<<' '<<(ck(now))<<'\n';
            cnt++;
            now--;
            //cout<<i<<' '<<now<<' '<<a[i]-a[now]<<' '<<caozo<<'\n';
        }else{
            break;
        }
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll dengcha;
    bool fl=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dengcha=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=dengcha){
            fl=0;
            break;
        }
    }
    if(fl){
        cout<<min(n,m/dengcha);
        return 0;
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}
