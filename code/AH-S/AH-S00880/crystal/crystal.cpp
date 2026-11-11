#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,a[N],m,minn,sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    for(int i=1;i<=n;i++) a[i]+=abs(minn);
    sort(a+1,a+n+1);
    sum[1]=0;
    for(int i=2;i<=n;i++) sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    ll ans=1;
    for(int i=2;i<=n;i++){
        if(sum[i]-sum[i-ans]-(i-ans-1)*(a[i]-a[i-ans])<=m) ans++;
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
