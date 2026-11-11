#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,r,mid,mx,a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=i;
        r=n;
        while(l<r){
            mid=(l+r+1)/2;
            ll k=a[mid]*(mid-i+1)-(sum[mid]-sum[i-1]);
            if(k>m){
                r=mid-1;
            }else{
                l=mid;
            }
        }
        if(l-i+1>mx){
            mx=l-i+1;
        }
    }
    cout<<mx;
    return 0;
}
