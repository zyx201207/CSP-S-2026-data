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

struct Edge{
    ll v,nxt;
};

struct info{
    ll u,v;
};

const ll maxn=1e6+5;
Edge e[maxn<<1];
info g[maxn];
bool tag[maxn];
ll f[maxn];
ll head[maxn],ecur;
ll dis[maxn];
ll t,n,k,c;

void add_edge(ll u,ll v)  {
    ++ecur;
    e[ecur]={v,head[u]};
    head[u]=ecur;
    return;
}

ll cntbit(ll x) {
    ll ret=0;
    while(x)  {
        if(x&1) {
            ++ret;
        }
        x>>=1;
    }
    return ret;
}

ll find(ll x) {
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}

void add_tag(ll x) {
    fill(tag+1,tag+1+n,0);
    for(ll i=0;i<n;++i) {
        if((1ll<<i)&x) {
            tag[i+1]=1;
        }
    }
    return;
}

ll check() {
    //我们检查连通块的数量
    iota(f+1,f+1+n,1);

    for(ll i=1;i<n;++i) {
        if(tag[g[i].u]&&tag[g[i].v]&&find(g[i].u)!=find(g[i].v)) {
            f[find(g[i].u)]=find(g[i].v);
        }
    }

    //我们检查连通块的数量十分是2
    set<ll> s;
    fill(dis+1,dis+1+n,inf);
    queue<ll> que;
    for(ll i=1;i<=n;++i) {
        if(!tag[i]) {
            continue;
        }
        s.insert(find(i));
        dis[i]=0;
        que.push(i);
    }
    if(s.size()>2) {
        return inf;
    }

    //联通块的数量小于2
    while(que.size()) {
        ll u=que.front();
        que.pop();
        for(ll i=head[u];i;i=e[i].nxt) {
            ll v=e[i].v;
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                que.push(v);
            }
        }
    }

    //找到最大值
    ll ret=0;
    for(ll i=1;i<=n;++i) {
        ret=max(ret,dis[i]);
    }
    return ret;
}

void subtask1() {
    ll ans=inf;
    for(ll i=1;i<(1ll<<n);++i) {
        if(cntbit(i)!=k) {
            continue;
        }
        add_tag(i);
        ll ret=check();
        ans=min(ans,ret);
    }
    printf("%lld\n",ans);
    return;
}

void subtask2() {
    ll ans=inf;
    for(ll i=1;i<=n;++i) {
        tag[i]=1;
        for(ll j=i+1;j<=n;++j) {
            tag[j]=1;
            ll ret=check();
            ans=min(ans,ret);
            tag[j]=0;
        }
        tag[i]=0;
    }
    printf("%lld\n",ans);
    return;
}

void init() {
    ecur=0;
    fill(head+1,head+1+n,0);
    return;
}

void work() {
    n=read();
    k=read();

    if(n==k) {
        puts("0");
        return;
    }

    init();

    for(ll i=1;i<n;++i) {
        ll u,v;
        u=read();
        v=read();
        add_edge(u,v);
        add_edge(v,u);
        g[i]={u,v};
    }

    if(n<=10) {
        //直接暴力枚举方案
        subtask1();
        return;
    }
    if(k==2) {
        //暴力枚举使用的点
        subtask2();
    }
    if(ll(n/2)+2-k<=0) {
        puts("1");
        return;
    }
    printf("%lld",ceil(double(ll(n/2)+2-k)/(double)k)+1);
    return;
}

int main() {
	//freopen("hub.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

    c=read();
    t=read();

    while(t--) {
        work();
    }


	return 0;
}
