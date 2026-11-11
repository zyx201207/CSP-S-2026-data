#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int maxn=5e5+10;
const ll inf=4e18;
#define filename "crystal"
//#define pos(i) (upper_bound(a+1,a+n+1,nx[i])-a)
#define rep(i,a,b) for(int i=(a);i<=(ll)b;++i)
#define getc getchar_unlocked()
#define putc putchar_unlocked
ll re(){
	ll res=0;bool s=0;char c=getc;
	for(;!isdigit(c);c=getc) s|=c=='-';
	for(;isdigit(c);c=getc) res=(res<<3)+(res<<1)+(c-'0');
	return s?-res:res;
}
void wr(ll x){
	if(x<0) putc('-'),x=-x;
	if(x>9) wr(x/10);
	putc(x%10+'0');
}ll n,m;
ll a[maxn];
ll ans=-inf;
ll f(ll x)
{
    ll me=m,cnt=0,ne=0;
    bool ok=1;
    rep(i,1,maxn)
        if(a[i]>x) break;
        else ne++;
    for(int i=ne;i>0;i--)
    {
        if((x-a[i])<=me) me-=(x-a[i]),cnt++;
        else{ok=0;break;}
    }
    ans=max(ans,cnt);
    return cnt;
}
ll nx[maxn];
signed main()
{
	//ios::sync_with_stdio(false);cin.tie(nullptr);
	#if 1
		freopen(filename".in","r",stdin);
		freopen(filename".out","w",stdout);
	#endif
    n=re(),m=re();
    rep(i,1,n) a[i]=re();
    a[n+1]=inf;
    sort(a+1,a+n+1);
    rep(i,1,n) nx[i]=a[i];
    int tot=unique(nx+1,nx+n+1)-nx-1;

    bool is_dc=1;
    int gc=nx[2]-nx[1];
    rep(i,2,tot)
        if(nx[i]-nx[i-1]!=gc)
        {
            is_dc=0;
            break;
        }
    if(is_dc)
        wr(f(nx[tot]));
    else
    {
        rep(i,1,tot) f(nx[i]);
        wr(ans);
    }
	return 0;
}
