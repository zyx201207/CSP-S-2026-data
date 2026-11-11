#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,m;
ll cnt;
ll ans=(1<<32)-1;
ll a[200010];
string str;
ll del[200010];
string b[200010];
string d_b(ll x){
    str="";
    while(x){
        str=char(x%2+48)+str;
        x/=2;
    }
    while(str.size()<=32){
        str='0'+str;
    }
    return str;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=d_b(a[i]);
    }
    for(ll i=0;i<=32;i++){
        cnt=0;
        for(ll j=1;j<=n;j++){
            if(del[j]==0){
                cnt+=b[j][i]-48;
            }
        }
        if(cnt>=m){
            for(ll j=1;j<=n;j++){
                if(del[j]==0&&b[j][i]!='1'){
                    del[j]=1;
                }
            }
        }
    }
    for(ll i=1;i<=n;i++){
        if(del[i]==0){
            ans&=a[i];
        }
    }
    printf("%lld",ans);
    return 0;
}
