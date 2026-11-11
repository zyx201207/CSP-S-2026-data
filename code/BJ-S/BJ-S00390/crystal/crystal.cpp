#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N],n,m,s[N];
bool check(ll mid){
    ll mn=1e18;
    for(int i=mid;i<=n;i++)mn=min(mn,a[i]*mid-s[i]+s[i-mid]);
    return mn<=m;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll l,r,mid,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    l=1,r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid))l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}