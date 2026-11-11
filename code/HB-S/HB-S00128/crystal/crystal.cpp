#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x = 0,h = 1;
    char ch = getchar();
    while(!(ch=='-'||('0'<=ch&&ch<='9'))) ch = getchar();
    if(ch=='-') h = -1;
    else x = ch-'0';
    ch = getchar();
    while('0'<=ch&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*h;
}
namespace G4M1{
    const ll N = 500010;
    ll n,a[N],m,sum[N];
    ll chk(ll x,ll y){return (a[y]*(y-x+1)-(sum[y]-sum[x-1]))<=m;}
    void main(){
        n = read(),m = read();
        for(ll i = 1; i <= n; i++) a[i] = read();
        sort(a+1,a+n+1);
        for(ll i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
        ll ans = 1;
        for(ll i = 1; i <= n; i++){
            ll L = 1,R = i,p = i;
            while(L<=R){
                ll mid = ((L+R)>>1);
                if(chk(mid,i)) R = mid-1,p = mid;
                else L = mid+1;
            }
            ans = max(ans,i-p+1);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    G4M1::main();
    return 0;
}
