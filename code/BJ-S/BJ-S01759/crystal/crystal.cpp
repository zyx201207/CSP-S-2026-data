#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=a[i]-a[i-1];
    }
    int l=1,r=2,ans=1;
    ll sum=c[2];
    while(l<=r&&r<=n){
        if(sum>m){
            sum-=(a[r]-a[l]);
            l++;
            continue;
        }
        ans=max(ans,r-l+1);
        if(sum<=m){
            sum+=1LL*(r-l+1)*c[r+1];
            r++;
        }
    }
    cout<<ans;
    return 0;
}
