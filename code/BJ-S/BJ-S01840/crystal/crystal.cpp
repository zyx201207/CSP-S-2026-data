#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n;ll a[N],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll cost=0;int it=1,ans=0;
    for(int i=1;i<=n;i++){
        cost+=1ll*((i-1)-it+1)*(a[i]-a[i-1]);
        while(cost>m) cost-=(a[i]-a[it]),it++;
        ans=max(ans,i-it+1);
    }
    cout<<ans<<'\n';
    return 0;
}