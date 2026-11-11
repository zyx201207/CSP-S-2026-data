

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar_unlocked
#define pc putchar_unlocked



ll read(){
    ll x=0,f=1;
    ll ch=gc();
    while(!isdigit(ch)) {
        if(ch=='-')f=-1;
        ch=gc();
    }
    while(isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
void write(ll x) {
    ll stk[48],t=0;
    if(x<0)pc('-'),x=-x;
    if(x==0)pc('0');
    while(x)stk[t++]=x%10,x/=10;
    for(int i=t-1;i>=0;i--) {
        pc(stk[i]^48);
    }
    pc('\n');
}
namespace cd{
    ll c,t,n,d;
    ll g[107][107],f[107][107],a[20007];
    ll cnt,ans,vis[107];
    ll dis[4007][4007];bool dv[1100007];
     struct nd {
        ll v,w;
    };
    bool operator<(nd x,nd y) {
        return x.w>y.w;
    }
    priority_queue<nd> pq;
    void dijkstra(ll s) {
        memset(dis[s],0x3f,sizeof(dis[s]));
        memset(dv,0,sizeof(dv));
        dis[s][s]=0;
        pq.push({s,0});nd u;
        while(!pq.empty()) {            u=pq.top();pq.pop();
            for(ll ed:g[u.v]) {
                if(dv[ed])continue;
                dv[ed]=1;
                if(dis[s][u.v]+1<dis[s][ed]) {
                    dis[s][ed]=dis[s][u.v]+1;
                    pq.push({ed,dis[s][ed]});
                }
            }
        }
    }
    void dfs(ll cur,ll frm,ll to,ll sel) {
        //printf("dfs(%lld,%lld,%lld,%lld)\n",cur,frm,to,sel);
        if(sel==dis[frm][to]) {
            if(cur==to)cnt++;
            return;
        }
                        if(cnt>2)return;


        for(int i=1;i<=n;i++) {
            if(g[cur][i]&&!vis[i]) {
                vis[i]=1;
                dfs(i,frm,to,sel+1);
                vis[i]=0;
                if(cnt>2)return;
            }
        }
    }
    int main() {
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
        c=read();t=read();
        while(t--) {
            n=read();d=read();ans=0;
            memset(g,-1,sizeof(g));            memset(f,0x3f,sizeof(g));
            for(int i=1;i<=n;i++)a[i]=read(),g[i][i]=0;
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
                if(a[j]-a[i]<=d) {
                    g[i][j]=j-i;f[i][j]=j-i;
                    g[j][i]=j-i;f[j][i]=j-i;
                }
            }
            for(int k=1;k<=n;k++) dijkstra(k);
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) {
                if(f[i][j]!=0x3f3f3f3f3f3f3f3fll) {
                    cnt=0;memset(vis,0,sizeof(vis));
                    dfs(i,i,j,0);
                    if(cnt==2)ans++;//,printf("%d %d\n",i,j);
                }
            }
            write(ans);
        }
        return 0;
    }
}
int main(){return cd::main();}


// woShiQU
//freopen
//woxihuannimen!
// nan yi 1=
// %%% julao
// luogu uid=1435654, @beijing101highSchoolKaodian.-104Seat1
// Oct31==Dec25?
// T1 done on 16:03
// T2 done on 16:48
