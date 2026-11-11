
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
    ll c,t,n,k;
    vector<ll> g[1000007];
    ll f[107][107][107];ll fa[1000007],vis[4007];ll u,v;ll d,cans,ans;
    ll bck[4007],bt;
    ll find(ll x) {
        if(x==fa[x])return x;
        return fa[x]=find(fa[x]);
    }
    void merge(ll x,ll y) {
        x=find(x),y=find(y);
        if(x!=y)fa[x]=y;
    }
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
    void dfs(ll sel,ll cur) {
        if(sel==k) {

            bt=0;
            for(int i=1;i<=n;i++) if(vis[i])bck[bt++]=i;
            for(int i=1;i<=n;i++)fa[i]=i;
            bt=k;
            for(int i=0;i<bt;i++) {
                for(ll x:g[bck[i]]) {
                    if(vis[x])  merge(bck[i],x);
                }
            }
            ll t1=-1,t2=-1;
            for(int i=0;i<bt;i++) {
                if(t1==-1)t1=fa[bck[i]];
                if(fa[bck[i]]==t1) continue;
                if(fa[bck[i]]!=t1&&t2==-1)t2=fa[bck[i]];
                if(fa[bck[i]]!=t1&&fa[bck[i]]!=t2)goto no;
            }
            //for(int i=0;i<bt;i++) write(bck[i]);pc('\n');
            cans=0;
            for(int i=1;i<=n;i++) {
                if(vis[i])d=0;
                else {
                d=0x3f3f3f3f3f3f3f3fll;
                for(int j=0;j<bt;j++) d=min(d,dis[i][bck[j]]);
                }
                cans=max(cans,d);
            }
            ans=min(ans,cans);
            no:
            return;
        }
        for(int i=cur+1;i<=n;i++) {
            vis[i]=1;
            dfs(sel+1,i);
            vis[i]=0;
        }
    }
    int main() {
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
        c=read();t=read();
        while(t--) {
            n=read();k=read();memset(f,0x3f,sizeof(f));memset(vis,0,sizeof(vis));ans=0x3f3f3f3f3f3f3f3fll;
            for(int i=1;i<=n;i++)g[i].clear(),fa[i]=i;
            for(int i=1;i<n;i++) {
                u=read();v=read();
                g[u].push_back(v);
                g[v].push_back(u);

            }
            for(int i=1;i<=n;i++)dijkstra(i);
            dfs(0,0);
            write(ans);//pc('-');pc('\n');
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
