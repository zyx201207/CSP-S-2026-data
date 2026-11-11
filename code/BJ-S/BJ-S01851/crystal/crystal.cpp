#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[500005];
bool f1=1,f2=1;
ll d;
bool cmp(ll a,ll b){
    return a<b;
}
bool check(int y){
    int x=a[y];
    ll sum=0;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(sum>m) break;
        if(a[i]<=x){
            sum+=x-a[i];
            cnt++;
        }
    }
    if(sum<=m){
        ans=max(ans,cnt);
        return 1;
    }
    else return 0;
}
void solve1(){
    ans=0;
    ll l=1;
    ll r=n;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
}
void solve2(){
    ans=0;
    m/=d;
    ll cnt=0;
    for(int i=1;m>=0;i++){
        m-=i;
        cnt++;
    }
    cout<<cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    d=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(a[i]!=i) f1=0;
        if(i!=1 && a[i]-a[i-1]!=d) f2=0;
    }
    if(f1){
        solve1();
        return 0;
    }
    else if(f2){
        solve2();
        return 0;
    }
    for(int i=1;i<=n;i++){
        ll sum=0,cnt=0;;
        for(int j=i;j>=1;j--){
            sum+=a[i]-a[j];
            if(sum>m)break;
            cnt++;
        }
        ans=max(ans,cnt);
    }
    //check(res);
    cout<<ans;
    return 0;
}
