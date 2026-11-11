// Come on, it's our fight
// No bro why testcase so weak
#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=5e5+10;
ll n,m,l=1,ans,ori[N];
ull sum,a[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>ori[i];
    sort(ori+1,ori+n+1);
    for(ll i=2;i<=n;i++) a[i]=ori[i]-ori[i-1];
    for(ll r=1;r<=n;r++){
        sum+=a[r]*(r-l);
        while(sum>m) sum-=ori[r]-ori[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}