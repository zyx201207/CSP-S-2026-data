#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define g() getchar_unlocked()
ll re(){
    ll k=0,f=1;char ch=g();
    for(;!isdigit(ch);ch=g())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=g())k=(k<<1)+(k<<3)+(ch^48);
    return k*f;
}
void ww(ll x){
    if(x<0)putchar_unlocked('-'),x=-x;
    if(x<10){putchar_unlocked(x+48);return;}
    ww(x/10);
    putchar_unlocked((x%10)+48);
}
ll n,m,dp[505][505],d,q,w[500005];
struct t{ll x,y;};
vector<t>v2[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    n=re(),n=re(),m=re(),d=re(),q=re();
    for(ll i=1;i<=m;i++)w[i]=re();
    memset(dp,0x3f,sizeof(dp));
    for(ll i=1;i<=n;i++){
        ll k=re();dp[i][i]=0;
        while(k--){
            ll aa=re(),bb=re();
            v2[aa].push_back({i,bb});
        }
    }
    for(ll i=1;i<=m;i++){
        for(ll j=0;j<v2[i].size();j++){
            for(ll k=0;k<j;k++){
                t x1=v2[i][j],x2=v2[i][k];
                dp[x1.x][x2.x]=min(dp[x1.x][x2.x],x1.y+x2.y);
                dp[x2.x][x1.x]=min(dp[x2.x][x1.x],x2.y+x1.y);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++)dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
        }
    }
    while(q--){
        ll aa=re(),bb=re(),ans=0x3f3f3f3f3f3f3f3f;
        for(ll i=0;i<v2[aa].size();i++){
            for(ll j=0;j<v2[bb].size();j++){
                t x1=v2[aa][i],x2=v2[bb][j];
                ans=min(ans,dp[x1.x][x2.x]+x1.y+x2.y);
            }
        }
        ww(ans+w[aa]+w[bb]);putchar('\n');
    }
    return 0;
}
