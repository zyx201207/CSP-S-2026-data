#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10,M=3e5+10;
ll a[N];
ll cnt[M];
bool b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++){
        memset(b,1,sizeof b);
        for(ll j=i;j<=n;j++){
            cnt[a[j]]++;
            bool f=0;
            for(ll k=i;k<=j-1;k++){
                if(a[k]==a[j]&&b[k])f=1;
                if(f&&b[k]){
                    cnt[a[k]]--;
                    b[k]=0;
                }
            }
        }
    }
    for(ll i=1;i<=m;i++)printf("%lld ",cnt[i]);
    return 0;
}
