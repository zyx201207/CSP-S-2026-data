#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000001],s[1000001],ans;
int check(int x){
    if(x>n)return 0;
    int t=9e18;
    for(int i=x;i<=n;i++)t=min(t,a[i]*x-s[i]+s[i-x]);
    return t<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=30;i>=0;i--)ans|=check(ans|1ll<<i)<<i;
    cout<<ans;
    return 0;
}
