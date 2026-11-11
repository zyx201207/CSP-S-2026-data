#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //a[i]=i;
    }
    sort(a+1,a+n+1);
    ll ans=-1;
    int l=1,r=n;
    while(l<r){
        int i=(l+r)/2+1;
        ll mid=a[i];
        ll te_m=m;
        ll sum=1;
        bool flag=0;
        for(int j=i-1;j>=1;j--){
            if(te_m>=mid-a[j]){
                te_m-=mid-a[j];
                sum++;
            }else{
                flag=1;
                break;
            }
            //cout<<i<<" "<<j<<" "<<mid-a[j]<<" "<<te_m<<" "<<sum<<endl;
        }
        for(int j=i;i<=n;j++){
            if(a[j+1]==a[j]) sum++;
            else break;
        }
        //cout<<endl;
        ans=max(ans,sum);
        if(flag) r=i-1;
        else l=i;
    }
    cout<<ans<<endl;
    return 0;
}
