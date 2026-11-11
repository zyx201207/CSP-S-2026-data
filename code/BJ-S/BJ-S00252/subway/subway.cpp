#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int c,n,m,d,q;
long long w[N];
int hd[N],nxt[N],to[N];
long long val[N];
int cnt;
long long a[N],t[N];
long long dis[N];
void add(int u,int v,long long w){
    nxt[++cnt] = hd[u];
    to[cnt] = v;
    val[cnt] = w;
    hd[u] = cnt;
}
struct T{
    int x,ww;
    bool friend operator < (T fir,T sec){
        return fir.ww < sec.ww;
    }
};
priority_queue<T>pq;
void dij(int x,int y){
    pq.push((T){x,0});
    while(pq.size()){
        int u = pq.top().x;
        pq.pop();
        //cout << u << "\n";
        if(dis[u] == 1e17){
            continue;
        }
        for(int i = hd[u];i;i = nxt[i]){
            int v = to[i];
            if(val[i] + dis[u] < dis[v]){
                dis[v] = val[i] + dis[u];
                pq.push((T){v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j <= k;j++){
            scanf("%lld%lld",&a[j],&t[j]);
            if(j > 1) add(a[j] + i * m,a[j - 1] + i * m,0);
            if(j > 1) add(a[j - 1] + i * m,a[j] + i * m,0);
            add(a[j] + (n + 1) * m,a[j] + i * m,t[j]);
            add(a[j] + i * m,a[j] + (n + 1) * m,t[j]);
        }
    }
    while(q--){
        for(int i = 0;i <= m;i++){
            for(int j = 0;j <= n + 1;j++){
                dis[i + j * m] = 1e17;
            }
        }
        int x,y;
        scanf("%d%d",&x,&y);
        dis[x + (n + 1) * m] = 0;
        dij(x + (n + 1) * m,y + (n + 1) * m);
        long long ans = dis[y + (n + 1) * m] + w[x] + w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
