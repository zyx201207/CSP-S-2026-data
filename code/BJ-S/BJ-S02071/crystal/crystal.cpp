#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
using namespace std;
ll n,m;
ll a[maxn];
ll ans;
ll sum[maxn];
inline ll getsum(ll x,ll y){
    return sum[y]-sum[x-1];
}
inline bool cmp(ll mid){

    for(int i=n;i>=mid;i--){
        ll val=(mid-1)*a[i]-getsum(i-mid+1,i-1);
        /*
        for(int j=i-mid+1;j<=i;j++){
            cout<<a[j]<<" ";
        }
        cout<<"---> "<<val<<endl;
        */
        if(val<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];

    ll l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        //cout<<"mid:"<<mid<<endl;
        if(cmp(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
