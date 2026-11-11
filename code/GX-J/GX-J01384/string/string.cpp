#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1073741824;
char s[N];
string t1,t2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0,tot=0;
    scanf("%lld",&n);
    while(n--){
        ll d;
        char c;
        scanf("%lld %c",&d,&c);
        for(ll i=1;i<=d;i++) s[++tot]=c;
    }
    if(tot%2==1){
        for(ll i=1;i<=tot/2+1;i++) t1+=s[i];
        for(ll i=tot;i>=tot/2+1;i--) t2+=s[i];

        for(ll i=0;i<=tot/2+1;i++){
            if(t1[i]!=t2[i]) ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
