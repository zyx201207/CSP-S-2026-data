#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N],f[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
    ll maxn=-1,maxj,maxk;
    for(ll i=1;i<m;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=j+1;k<=n;k++){
                if(maxn<a[j]&a[k]&&f[j]!=1||f[k]!=1){
                    maxn=a[j]&a[k];
                    maxj=j,maxk=k;
                }
            }
        }
        a[maxj]=maxn,f[maxk]=1;
    }
    printf("%lld",maxn);
    return 0;
}
