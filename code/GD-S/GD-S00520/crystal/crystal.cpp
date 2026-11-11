#include<bits/stdc++.h>
using namespace std;
//#define int long long;
#define rep(x,y,z) for(register int x=y;x<=z;++x)
#define per(x,y,z) for(register int x=y;x>=z;--x)
#define endl '\n'
typedef long long ll;
const int N=500005;
ll n,m,a[N],sum,j=1,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n){
        sum+=a[i];
        while(a[i]*(i-j+1)-sum>m)sum-=a[j],++j;
        ans=max(ans,(i-j+1));
    }
    cout<<ans<<endl;
    return 0;
}//20min