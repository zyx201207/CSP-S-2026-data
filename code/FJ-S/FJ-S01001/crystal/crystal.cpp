#include<bits/stdc++.h>
namespace xcy{
typedef long long ll;
typedef std::pair<ll,ll> sp;
const ll MAXN=500005;
#define fi first
#define se second
#define emp emplace
#define emb emplace_back
#define ppb pop_back
#define vc std::vector
ll a[MAXN],n,m,i,j,k,ans;

inline void fr(ll &X){X=0;ll A=1;char C=getchar();while(!isdigit(C)&&C!='-')C=getchar();if(C=='-')A=-1,C=getchar();while(isdigit(C))X=X*10+C-'0',C=getchar();X*=A;}
inline void _fo(const ll X){if(!X)return;_fo(X/10);putchar(X%10+'0');}
inline void fo(ll X,char C=' '){if(!X)putchar('0');if(X<0)putchar('-'),X=-X;_fo(X),putchar(C);}

int mian()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    fr(n),fr(m);for(i=1;i<=n;++i)fr(a[i]);
    std::sort(a+1,a+n+1);for(i=2,j=ans=1;i<=n;++i)
    {
        m-=(a[i]-a[i-1])*(i-j);
        while(m<0)m+=a[i]-a[j],++j;ans=std::max(ans,i-j+1);
    }
    fo(ans,'\n');return 0;
}}
int main(){return xcy::mian();}