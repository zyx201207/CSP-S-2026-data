#include<stdio.h>
#include<vector>
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    std::vector<ll> a(n+1);
    std::vector<char> c(n+1),s;
    for(ll i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=a[i];j++){
            s.push_back(c[i]);
        }
    }
    // for(ll i=0;i<s.size();i++){
    //     prllf("%c",s[i]);
    // }
    ll ans=0;
    for(ll i=0;i<=s.size()/2;i++){
        ans+=s[i]!=s[s.size()-1-i];
    }
    printf("%lld\n",ans);
    return 0;

}