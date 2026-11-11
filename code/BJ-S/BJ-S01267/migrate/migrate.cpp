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
const ll maxn=2e6+5;

struct info{
    ll u,w;

    bool operator<(const info&other)const{
        return w>other.w;
    }
};

struct node{
    ll minn,tot;

    node() {
        minn=inf;
        tot=0;
    }
};

node seg[maxn<<2];
ll dis[maxn],cnt[maxn];
bool tag[maxn];
ll a[maxn];
ll n,d;
ll c,t;

node merge(node a,node b) {
    if(a.minn<b.minn) {
        return a;
    }
    if(a.minn>b.minn) {
        return b;
    }
    node ret;
    ret.minn=a.minn;
    ret.tot=a.tot+b.tot;
    return ret;
}

node ask(ll p,ll l,ll r,ll x,ll y) {
    if(x<=l&&r<=y) {
        return seg[p];
    }
    ll mid=(l+r)>>1;
    node ret;
    if(x<=mid) {
        ret=ask(ls(p),l,mid,x,y);
    }
    if(y>mid) {
        ret=merge(ret,ask(rs(p),mid+1,r,x,y));
    }
    return ret;
}

void chg(ll p,ll l,ll r,ll x,ll y,ll z) {
    if(l==r) {
        seg[p].minn=y;
        seg[p].tot=z;
        return;
    }
    ll mid=(l+r)>>1;
    if(x<=mid) {
        chg(ls(p),l,mid,x,y,z);
    }else{
        chg(rs(p),mid+1,r,x,y,z);
    }
    seg[p]=merge(seg[ls(p)],seg[rs(p)]);
    return;
}


ll len(ll l,ll r) {
    return a[r]-a[l];
}

void djstl(ll s) {
    fill(dis+1,dis+1+n,inf);
    fill(cnt+1,cnt+1+n,0);
    fill(tag+1,tag+1+n,0);
    dis[s]=0;
    cnt[s]=1;
    queue<info> que;
    que.push({s,0});
    while(que.size()) {
        info now=que.front();
        que.pop();
        if(now.w!=dis[now.u]||tag[now.u]) {
            continue;
        }
        tag[now.u]=1;
        //我们开始扩展
        for(ll v=now.u+1;v<=n&&len(now.u,v)<=d;++v) {
            //我们枚举条到那个点
            if(dis[v]==dis[now.u]+1) {
                cnt[v]+=cnt[now.u];
                if(cnt[v]>2) {
                    cnt[v]=inf;
                }else{
                    que.push({v,dis[v]});
                }
                continue;
            }
            if(dis[v]>dis[now.u]+1) {
                dis[v]=dis[now.u]+1;
                cnt[v]=cnt[now.u];
                que.push({v,dis[v]});
                continue;
            }
        }
    }
}

void subtask() {
    ll ans=0;
    for(ll i=1;i<=n;++i) {
        djstl(i);
        //计数
        for(ll j=i+1;j<=n;++j) {
            if(cnt[j]==2) {
                ++ans;
            }
        }
    }
    printf("%lld\n",ans);
    return;
}

void subtask2() {
    ll sub=a[2]-a[1],ans=0;
    if(d<2*sub) {
        puts("0");
        return;
    }

    for(ll i=1;i<=n;++i) {
        //找到方案数量为2的连续子段
        ll x=0,y=0;
        for(ll l=i+1,r=n;l<=r;) {
            ll mid=(l+r)>>1;
            if(len(i,mid)<=d) {
                //一次就可以跳到了
                x=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //找到两次可以跳到的最大的
        for(ll l=i+1,r=n;l<=r;) {
            ll mid=(l+r)>>1;
            if(len(i,mid)>d&&len(i,mid)<=2*d) {
                //一次就可以跳到了
                x=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //(l,r]就是可以两次跳到的
        if(!x||!y) {
            continue;
        }
        ans+=y-x;
    }
    printf("%lld\n",ans);
    return;
}

void subtask3() {
    ll ans=0;
    for(ll i=1;i<=n;++i) {
        //找到方案数量为2的连续子段
        ll x=0,y=0;
        for(ll l=i+1,r=n;l<=r;) {
            ll mid=(l+r)>>1;
            if(len(i,mid)<=d) {
                //一次就可以跳到了
                x=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //找到两次可以跳到的最大的
        for(ll l=i+1,r=n;l<=r;) {
            ll mid=(l+r)>>1;
            if(len(i,mid)>d&&len(i,mid)<=2*d) {
                //一次就可以跳到了
                x=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        //(l,r]就是可以两次跳到的
        if(!x||!y) {
            continue;
        }
        ans+=y-x;
    }
    printf("%lld\n",ans);
    return;
}

ll dp[maxn],f[maxn];

void getdp(ll x) {
    dp[x]=0;
    f[x]=1;
    chg(1,1,n,x,dp[x],f[x]);
    for(ll i=x+1;i<=n;++i) {
        ll pos=-1;
        for(ll l=x,r=i-1;l<=r;) {
            ll mid=(l+r)>>1;
            if(a[i]-a[mid]<=d) {
                pos=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(pos==-1) {
            break;
        }
        node tmp=ask(1,1,n,pos,i-1);
        dp[i]=tmp.minn+1;
        f[i]=tmp.tot;
        chg(1,1,n,i,dp[i],f[i]);
    }
    return;
}

void subtask4() {
    //我们动态规划求解
    ll ans=0;
    for(ll i=1;i<=n;++i) {
        fill(dp+1,dp+1+n,inf);
        fill(f+1,f+1+n,0);
        fill(seg+1,seg+1+4*n,node());
        getdp(i);
        for(ll j=i+1;j<=n;++j) {
            if(f[j]==2) {
                ++ans;
            }
        }
    }
    printf("%lld\n",ans);
    return;
}

void work()  {
    n=read();
    d=read();

    fill(a+1,a+1+n,0);
    for(ll i=1;i<=n;++i) {
        a[i]=read();
    }

    //我们考虑n^2的做法
    if(n<=5000) {
        //subtask();
        subtask4();
        return;
    }
    if(c==12||c==11) {
        subtask2();
        return;
    }
    subtask3();
    return;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    //freopen("input.txt","r",stdin);

    c=read();
    t=read();

    while(t--) {
        work();
    }

	return 0;
}
