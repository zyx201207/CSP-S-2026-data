#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll sum[500005];
ll maxn;
ll l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(ll r=1;r<=n;r++){
        sum[r]=a[r]-a[r-1];
        m-=sum[r]*(r-l);
        while(m<0){
            m+=a[r]-a[l];
            l++;
        }
        //cout<<l<<' '<<r<<' '<<r-l+1<<endl;
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}
