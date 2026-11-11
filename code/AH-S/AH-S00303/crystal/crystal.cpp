/*
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N];
ll t[N],sum[N];
bool check(int u){
    for(int i=u;i<=n;i++){
        ll v=0;
        if(i==u) v=t[i];
        else v=t[i]-t[i-u+1]-(i-u)*(sum[i]-sum[i-u+1]);
        if(v<=m){
            //cout<<"["<<i-u+1<<","<<i<<"] len:"<<u<<" "<<v<<"\n";
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=a[1];
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(a[i]-a[i-1]);
        t[i]=t[i-1]+(max(1,i-1))*(a[i]-a[i-1]);
        //cout<<sum[i]<<" ";
    }
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    //ll ans=0;
    //for(int i=4;i<=3849;i++){
    //    ans+=a[3849]-a[i];
    //}
    //cout<<ans;
    //for(int i=n;i>=1;i--){
    //    if(t[i]<=m){
    //        cout<<i;
    //        break;
     //   }
    //}
    return 0;
}
