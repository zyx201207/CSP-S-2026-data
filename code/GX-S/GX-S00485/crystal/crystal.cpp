#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,cnt=0,m,ans=1,len=0;
    cin>>n>>m;
    vector<ll> a(n+5,0),sum(n+5,0),d(n+5,0),p(64,1);
    for(ll i=1;i<=n;i=1<<cnt)p[cnt++]=i;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a.begin()+1,a.begin()+1+n);
    for(ll i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
        d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    for(ll i=1;i<=n;i++){
        len=0;
        for(ll j=cnt-1;j>=0;j--)while(len+i+p[j]<=n && m>=(d[len+i+p[j]]-(i-1)*a[len+i+p[j]]+sum[i-1]))len+=p[j];
        ans=max(ans,len+1);
    }
    cout<<ans<<endl;
    return 0;
}
