#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500010];
struct eg{
    ll t,v;
};
vector<eg> G;
ll r(){
    ll f=1,x=0;
    char c=getchar();
    while(c){
        if(c<'0'||c>'9'){
            if (c=='-') f=-1;
            else break;
        }
        if(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
        }
    }
    return x;
}
void w(ll x){
    if(x<0)x=0-x;
    if(x>10)w(x/10);
    putchar('0'+x%10);
}
int main(){
    c=r();
    n=r();
    m=r();
    d=r();
    q=r();
    for(ll i=1;i<=m;i++)w[i]=r();
    for(ll i=i;i<=n;i++){
        ll k=r();
        for(ll j=1;j<=n;j++){
            ll a=r();
            ll k=r();
        }
    }
    
    return 0;
}