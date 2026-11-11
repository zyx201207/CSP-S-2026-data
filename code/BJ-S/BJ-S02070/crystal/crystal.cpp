#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,m,t=1,s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        m-=(i-t)*(a[i]-a[i-1]);
        while(m<0) m+=a[i]-a[t++];
        s=max(s,i-t+1);
    }
    printf("%lld",s);
    return 0;
}