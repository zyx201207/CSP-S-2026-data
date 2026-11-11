#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n;
ll l,r;
ll ans;
char cl,cr;
ll suml,sumr;
ll a[2000010];
char c[2000010][5];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld%s",&a[i],c[i]);
    }
    l=1;
    r=n;
    while(l<=r){
        if(a[l]==a[r]){
            if(c[l][0]!=c[r][0]){
                ans+=a[l];
            }
            l++;
            r--;
            continue;
        }
        if(a[l]<a[r]){
            if(c[l][0]!=c[r][0]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
            continue;
        }
        if(c[l][0]!=c[r][0]){
            ans+=a[r];
        }
        a[l]-=a[r];
        r--;
    }
    printf("%lld",ans);
    return 0;
}
