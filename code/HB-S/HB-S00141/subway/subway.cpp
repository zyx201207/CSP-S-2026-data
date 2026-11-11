#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int read() {
    int ans=0,flag=1; char c=getchar();
    while(c<'0'||c>'9') {
		if(c=='-') flag=-1;
		c=getchar();
	}
    while(c>='0'&&c<='9') {ans=ans*10+c-'0'; c=getchar();}
    return ans*flag;
}
priority_queue<pr,vector<pr>,greater<pr> > que;
bool vis[1010];
int c,n,m,d,q,dis_ex[500010],head[1000010],cnt;
long long ori[510][510];
long long dis[510][510],tdis[1010];
struct edge{int to,nxt,val;}e[2000010];
struct query_{int pl,u,v; long long ans;}query[100010];
struct temp{int to,val;};
void add_edge(int u,int v,int w) {
    e[++cnt].to=v;
    e[cnt].val=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
bool cmp(query_ a,query_ b) {return (a.u==b.u)?(a.v<b.v):(a.u<b.u);}
bool cmp2(query_ a,query_ b) {return a.pl<b.pl;}
void pre_work() {
    temp cross[30];
    int tot=0;
    for(int i=n+1;i<=n+m;i++) {
        tot=0;
        // cout<<"now: "<<i<<'\n';
        for(int j=head[i];j;j=e[j].nxt) {
            cross[++tot].to=e[j].to;
            cross[tot].val=e[j].val;
            // cout<<"cross: "<<cross[tot].to<<" "<<cross[tot].val<<'\n';
        }
        // cout<<'\n';
        // cout<<"tot: "<<tot<<'\n';
        for(int j=1;j<=tot;j++) {
            for(int k=j+1;k<=tot;k++) {
                ori[cross[j].to][cross[k].to]=min(ori[cross[j].to][cross[k].to],1ll*(cross[j].val+cross[k].val));
                ori[cross[k].to][cross[j].to]=ori[cross[j].to][cross[k].to];
            }
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout<<ori[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}
void dijkstra(int x) {
    memset(tdis,0x3f,sizeof(tdis));
    memset(vis,0,sizeof(vis));
    tdis[x]=0;
    que.push(make_pair(0,x));
    while(!que.empty()) {
        int t=que.top().second;
        que.pop();
        if(vis[t]) continue;
        vis[t]=1;
        for(int i=1;i<=n;i++) {
            if(i!=t&&ori[i][t]!=0x3f3f3f3f) {
                if(tdis[t]+ori[i][t]<tdis[i]) {
                    tdis[i]=tdis[t]+ori[i][t];
                    que.push(make_pair(tdis[i],i));
                }
            }
        }
    }
}
void get_dis() {
    for(int i=1;i<=n;i++) {
        dijkstra(i);
        for(int j=1;j<=n;j++) {
            dis[i][j]=dis[j][i]=tdis[j];
        }
    }
}
long long solve(int st,int ed) {
    long long ans=LONG_LONG_MAX;
    temp cs1[30],cs2[30];
    int tot1=0,tot2=0;
    for(int i=head[st];i;i=e[i].nxt) {
        cs1[++tot1].to=e[i].to;
        cs1[tot1].val=e[i].val;
    }
    for(int i=head[ed];i;i=e[i].nxt) {
        cs2[++tot2].to=e[i].to;
        cs2[tot2].val=e[i].val;
    }
    for(int i=1;i<=tot1;i++) {
        for(int j=1;j<=tot2;j++) {
            ans=min(ans,1ll*(dis[cs1[i].to][cs2[j].to]+cs1[i].val+cs2[j].val));
        }
    }
    return ans+dis_ex[st-n]+dis_ex[ed-n];
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(ori,0x3f,sizeof(ori));
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) dis_ex[i]=read();
    for(int i=1,t;i<=n;i++) {
        t=read();
        for(int j=1,v,w;j<=t;j++) {
            v=read(),w=read();
            add_edge(i,v+n,w);
            add_edge(v+n,i,w);
        }
    }
    // debug
    // for(int i=1;i<=n+m;i++) {
    //     cout<<i<<": ";
    //     for(int j=head[i];j;j=e[j].nxt) {
    //         cout<<"{"<<e[j].to<<","<<e[j].val<<"} ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<n<<" "<<m<<" "<<d<<" "<<q<<'\n';
    for(int i=1;i<=q;i++) {
        query[i].pl=i;
        query[i].u=read(),query[i].v=read();
    }
    sort(query+1,query+q+1,cmp);
    pre_work();
    get_dis();
    for(int i=1;i<=q;i++) query[i].ans=solve(query[i].u+n,query[i].v+n);
    sort(query+1,query+q+1,cmp2);
    for(int i=1;i<=q;i++) cout<<query[i].ans<<'\n';
    return 0;
}
