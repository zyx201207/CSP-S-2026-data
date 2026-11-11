#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 500010
using namespace std;

ll n,m,ans;
ll a[MAXN],sum[MAXN];

ll calc(int l,int r){
    return (r-l)*a[r]-(sum[r-1]-sum[l-1]);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ll l=1,r=i-1;
        while(l<r){
            int mid=(l+r)/2;
            //cout<<mid<<" "<<i<<" "<<calc(mid,i)<<endl;
            if(calc(mid,i)>m) l=mid+1;
            else r=mid;
        }
        //cout<<l<<" "<<r<<endl;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
