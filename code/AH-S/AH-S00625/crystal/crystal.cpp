#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N=500010;
ll n,m,a[N],b[N],f[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    ffor(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    ffor(i,1,n-1) b[i]=a[i+1]-a[i];
    ffor(i,1,n) f[i]=f[i-1]+b[i];
    ll l=1,s=0,c=1,ans=1;
    ffor(r,1,n){
        s+=b[r]*(r-l+1);c++;
        while(l!=r&&s>m){
            s-=f[r]-f[l-1];c--;
            l++;
        }
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}