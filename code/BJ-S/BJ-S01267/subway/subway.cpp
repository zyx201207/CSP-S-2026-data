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

struct info{
    ll u,t;
};

const ll inf=1e18;
const ll maxm=5e5+5;
const ll maxn=505;
vector<info> sta[maxm];//记录每个地铁站有那些线路
ll w[maxm]; //记录每个站台从地铁口到站厅的时间
ll dis[maxn][maxn];
ll c,n,m,d,q;

void floyd() {
    for(ll k=1;k<=n;++k) {
        for(ll i=1;i<=n;++i) {
            for(ll j=1;j<=n;++j) {
                if(dis[i][k]+dis[k][j]<dis[i][j]) {
                    dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}

int main() {
	//freopen("input.txt","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

    c=read();
    n=read();
    m=read();
    d=read();
    q=read();

    for(ll i=1;i<=m;++i) {
        w[i]=read();
    }

    for(ll i=1;i<=n;++i) {
        //我们遍历线路
        ll k;
        k=read();
        for(ll j=1;j<=k;++j) {
            ll a,b;//经过地铁站a 到达站厅的时间为b
            a=read();
            b=read();
            sta[a].push_back({i,b});
        }
    }

    //初始化dis
    for(ll i=1;i<=n;++i) {
        fill(dis[i]+1,dis[i]+1+n,inf);
    }

    //我们建立图
    for(ll i=1;i<=m;++i) {
        ll sz=sta[i].size();
        for(ll j=0;j<sz;++j) {
            ll u=sta[i][j].u,w1=sta[i][j].t;
            for(ll k=j+1;k<sz;++k) {
                //对i j建立图
                ll v=sta[i][k].u,w2=sta[i][k].t;
                if(dis[u][v]>w1+w2) {
                    dis[u][v]=dis[v][u]=w1+w2;
                }
            }
        }
    }

    for(ll i=1;i<=n;++i) {
        dis[i][i]=0;
    }

    //建立图完成
    //弗洛伊德
    floyd();

    //处理询问
    while(q--) {
        ll x,y;
        x=read();
        y=read();
        if(x==y) {
            puts("0");
        }
        ll ans=inf;
        //我们枚举使用的地铁线路
        for(ll i=0;i<sta[x].size();++i) {
            for(ll j=0;j<sta[y].size();++j) {
                ll u=sta[x][i].u,v=sta[y][j].u;
                ll tmp=dis[u][v]+sta[x][i].t+sta[y][j].t;
                ans=min(ans,tmp);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }

	return 0;
}
