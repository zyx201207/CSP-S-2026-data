#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define req(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=5e5+5;
ll n,a[N],m,s[N];
bool chk(ll le,ll ri){
    ll sum=(ri-le+1)*a[ri]-(s[ri]-s[le-1]);
    return (sum<=m);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n)s[i]=s[i-1]+a[i];
    ll maxn=1;
    rep(i,1,n){
        ll L=1,R=i,ans=i;
        while(L<=R){
            ll mid=(L+R)/2;
            if(chk(mid,i)){
                ans=mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        maxn=max(maxn,i-ans+1);
    }
    cout<<maxn;
    return 0;
}