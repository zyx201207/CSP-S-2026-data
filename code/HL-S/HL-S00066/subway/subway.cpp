#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PI;
const int N=5e5+10;
int c,n,m,li,q;
int w[N];
vector<int> t[510];
vector<int> a[510];
int len[510];
LL rec[510][510];
vector<int> sy[N];
int f[N],times=0;
LL d[N];
struct node {
    int to,next,len;
} e[N*40];
int pre[N << 1],k=0;
priority_queue<PI,vector<PI>,greater<PI> > pq;
inline int read() {
    int x=0,f=1;
    char c=getchar();
    while(c < '0' || c > '9') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c >= '0' && c <= '9') {
        x=(x << 1)+(x << 3)+(c ^ 48);
        c=getchar();
    }
    return x * f;
}
inline void write(LL x) {
    if(x==0) {
        putchar('0');
        return ;
    }
    char st[22];
    int len=0;
    while(x) {
        st[len++]=x%10+'0';
        x/=10;
    }
    for(int i=len-1;~i;i--) putchar(st[i]);
}
inline void add(int u,int v,int len) {
    e[++k]={v,pre[u],len};
    pre[u]=k;
}
void dijkstra(int s) {
    for(int i=1;i<=n+m;i++) d[i]=1e18;
    while(!pq.empty()) pq.pop();
    d[s]=0;
    pq.push({0,s});
    int cnt=1;
    while(!pq.empty()) {
        PI h=pq.top();
        pq.pop();
        int p=h.second;
//        if(p > m) cnt++;
//        if(cnt==n) break;
        if(f[p]==times) continue;
        f[p]=times;
        for(int i=pre[p];i;i=e[i].next) {
            int to=e[i].to;
            int len=e[i].len;
            if(d[p]+len<d[to]) {
                d[to]=d[p]+len;
                pq.push({d[to],to});
            }
        }
    }
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),li=read(),q=read();
    for(int i=1;i<=m;i++) {
        w[i]=read();
    }
    for(int i=1;i<=n;i++) {
        len[i]=read();
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=len[i];j++) {
            int x,y;
            x=read(),y=read();
            a[i].push_back(x);
            t[i].push_back(y);
            sy[x].push_back(i);
        }
    }
    for(int i=1;i<=m;i++) {
        for(const auto &x:sy[i]) {
            int p=lower_bound(a[x].begin()+1,a[x].begin()+len[x]+1,i)-a[x].begin();
            add(i,m+x,t[x][p]);
            add(m+x,i,t[x][p]);
        }
    }
    for(int i=1;i<=n;i++) {
        ++times;
        dijkstra(i+m);
        for(int j=1;j<=n;j++) {
            rec[i][j]=d[j+m];
        }
    }
    while(q--) {
        int x,y;
        x=read(),y=read();
        LL ans=1e18;
        for(const auto &s:sy[x]) {
            for(const auto &e:sy[y]) {
                int tox=lower_bound(a[s].begin()+1,a[s].begin()+len[s]+1,x)-a[s].begin();
                int toy=lower_bound(a[e].begin()+1,a[e].begin()+len[e]+1,y)-a[e].begin();
                ans=min(ans,rec[s][e]+t[s][tox]+t[e][toy]+w[x]+w[y]);
            }
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
