#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    string s;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        ll a;
        char c;
        cin>>a>>c;
        for(ll j=1;j<=a;j++){
            s+=c;
        }
    }
    string a=s;
    ll j=0,ans=0;
    if(s.size()/2!=0){
        for(ll i=s.size()-1;i>s.size()/2;i--){
            if(a[j++]!=s[i])ans++;
        }
    }else{
        for(ll i=s.size()-1;i>=s.size()/2;i--){
            if(a[j++]!=s[i])ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
