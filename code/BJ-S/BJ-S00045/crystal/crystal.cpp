#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,l,r,ans;
ll m,str[500005],a[500005],p=0,k;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(ll i=1;i<n;i++)str[i]=a[i+1]-a[i];
    l=1;
    r=0;
    while(r<(n-1)){
        r++;
        p+=(r-l+1)*str[r];
        k+=str[r];
        while(p>m){
            p-=k;
            k-=str[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans+1;
    return 0;
}
