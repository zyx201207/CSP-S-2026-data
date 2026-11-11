#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define db double
using namespace std;
const ll mx=5e5+5;
ll n,m,a[mx],s[mx];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    ll now=1,ans=0;
    for(int i=1;i<=n;i++){
        while(a[i]*(i-now+1)-(s[i]-s[now-1])>m)now++;
        ans=max(ans,i-now+1);    
    }cout<<ans;
    return 0;
}