#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll n,m,a[500005],cost[500005],mina=1e17,ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll flag=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mina=min(mina,a[i]);
    }
    for(ll i=1;i<=n;i++){
        a[i]-=mina;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if((i>10)&&(a[i]-a[i-1]!=a[i-1]-a[i-2])){
            flag=0;
            break;
        }
    }
    if(flag==1){
        ll cha=a[3]-a[2];
        ll sum=0;
        for(int i=1;i<=n;i++){
            if(sum>m){
                cout<<i;
                return 0;
            }
            sum+=a[i];
        }
        cout<<n;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        cost[i]=cost[i-1]+(i-1)*(a[i]-a[i-1]);
//        cout<<cost[i]<<' ';
    }
//    cout<<cost[n-1]<<' '<<m<<endl;
//    cout<<endl;
    for(ll l=1;l<=n;l++){
        ll mid=upper_bound(cost+l+1,cost+n+1,m+cost[l])-cost-l;
//        ll le=l,r=n,num=m+cost[l];
//        while(l<r){
//            ll mid=(le+r)/2;
//            if(a[mid]>=num){
//                r=mid;
//            }else{
//                l=mid+1;
//            }
//        }
//        ll mid=upper_bound(a+l+1,a+n+1,m)-a-l;
//        cout<<mid<<' ';
        ans=max(ans,mid);
    }
    cout<<ans;
}
