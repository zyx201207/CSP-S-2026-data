#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=510;
const int M=500010;
const ll INF=0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
ll w[500010];
struct Edge {
    int v;
    ll d;
};
vector<Edge> sta[500010];
ll dis[510][510];

ll read() {
    ll x=0, ch=getchar();
    while (ch<'0'||ch>'9')
        ch=getchar();
    while (ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	c=read(), n=read(), m=read(), d=read(), q=read();
    for (int i=1; i<=m; ++i) {
        w[i]=read();
    }
    for (int i=1; i<=n; ++i) {
        int k;
        k=read();
        for (int j=1; j<=k; ++j) {
            int a; ll t;
            a=read(), t=read();
            sta[a].push_back((Edge) {i, t});
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            dis[i][j]=INF;
            if (i==j)
                dis[i][j]=0;
        }
    }
    for (int i=1; i<=m; ++i) {
        for (int j=0; j<sta[i].size(); ++j) {
            for (int k=j+1; k<sta[i].size(); ++k) {
                dis[sta[i][j].v][sta[i][k].v]=dis[sta[i][k].v][sta[i][j].v]=min(dis[sta[i][j].v][sta[i][k].v], sta[i][j].d+sta[i][k].d);
            }
        }
    }

    for (int k=1; k<=n; ++k)
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);

    while (q--) {
        int s, t;
        scanf("%d%d", &s, &t);
        ll ans=INF;
        for (auto i:sta[s]) {
            for (auto j:sta[t]) {
                ans=min(ans, dis[i.v][j.v]+i.d+j.d);
            }
        }
        printf("%lld\n", ans+w[s]+w[t]);
    }

    return 0;
}
