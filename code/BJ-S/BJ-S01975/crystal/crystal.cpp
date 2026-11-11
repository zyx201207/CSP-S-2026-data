#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
    }

    d[1]=0;
    ll ans=0,sum=0,last=0;

    for(ll l=1,r=1;r<n;){
        //cout<<"test1:"<<ans<<" "<<sum<<" "<<last<<endl;
            //printf("0: l:%lld r:%lld ans:%lld sum:%lld last:%lld\n",l,r,ans,sum,last);
        while(sum<=m&&r<n){
            //cout<<"test3:"<<l<<" "<<r<<" "<<ans<<" "<<sum<<" "<<last<<endl;
            ans=max(ans,r-l+1);
            r++;
            sum+=(r-l)*d[r];
            last+=d[r];
            //printf("1: l:%lld r:%lld ans:%lld sum:%lld last:%lld\n",l,r,ans,sum,last);
            //cout<<"test4:"<<l<<" "<<r<<" "<<ans<<" "<<sum<<" "<<last<<endl;
        }
        //cout<<"test5:"<<l<<" "<<r<<" "<<ans<<" "<<sum<<" "<<last<<endl;
        while(sum>m&&l<r){
            l++;
            sum-=last;
            last-=d[l];
            //printf("2: l:%lld r:%lld ans:%lld sum:%lld last:%lld\n",l,r,ans,sum,last);
            //cout<<"test6:"<<l<<" "<<r<<" "<<ans<<" "<<sum<<" "<<last<<endl;
        }
        ans=max(ans,r-l+1);
        //cout<<"test2:"<<ans<<" "<<sum<<" "<<last<<endl;
    }
    cout<<ans;
    return 0;
}
