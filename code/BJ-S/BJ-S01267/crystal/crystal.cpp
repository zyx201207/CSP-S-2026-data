#include <bits/stdc++.h>
#include <bits/extc++.h>

#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef long long ll;

ll read() {
	ll ret=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}

	while(c>='0'&&c<='9') {
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret*f;
}

ll fpow(ll a,ll b,ll mod) {
	ll ret=1;
	while(b) {
		if(b&1) {
			ret*=a;
			ret%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return ret;
}

const ll inf=1e18;
const ll maxn=5e5+5;

ll a[maxn],pre[maxn];
ll n,m;

ll sum(ll l,ll r) {
    return pre[r]-pre[l-1];
}

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    n=read();
    m=read();

    for(ll i=1;i<=n;++i) {
        a[i]=read();

    }

    sort(a+1,a+1+n);

    for(ll i=1;i<=n;++i) {
        pre[i]=pre[i-1]+a[i];
    }

    //我们枚举最大值
    ll ans=0;
    for(ll i=1;i<=n;++i) {
        //最大值为a[i]
        ll res=0;
        for(ll l=1,r=i;l<=r;) {
            ll mid=(l+r)>>1;
            ll tmp=a[i]*(i-mid+1)-sum(mid,i);
            if(tmp<=m) {
                res=i-mid+1;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,res);
    }

    printf("%lld\n",ans);
	return 0;
}
