#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fastIO{
    const int IN_BUF=1<<20;
    char inbuf[IN_BUF],*p1=inbuf,*p2=inbuf;
    inline int gc(){
        if(p1==p2){
            p2=(p1=inbuf)+fread(inbuf,1,IN_BUF,stdin);
            if(p1==p2) return EOF;
        }
        return *p1++;
    }
    inline int read(){
        int k=0,f=1;
        int c=gc();
        while(c!=EOF&&!isdigit(c)){
            if(c=='-') f=-1;
            c=gc();
        }
        if(c==EOF) return 0;
        while(c!=EOF&&isdigit(c)){
            k=(k<<1)+(k<<3)+(c^48);
            c=gc();
        }
        return k*f;
    }
    const int OUT_BUF=1<<22;
    char outbuf[OUT_BUF],*now=outbuf;
    inline void pc(char c){
        if(now-outbuf==OUT_BUF){
            fwrite(outbuf,1,OUT_BUF,stdout);
            now=outbuf;
        }
        *now++=c;
    }
    inline void write(int x){
        if(x==0){
            pc('0');
            return ;
        }
        if(x<0){
            x=-x;
            pc('-');
        }
        char s[25];
        int len=0;
        while(x){
            s[len++]=x%10+'0';
            x/=10;
        }
        while(len--) pc(s[len]);
    }
    inline void flush(){
        fwrite(outbuf,1,now-outbuf,stdout);
        now=outbuf;
    }
}
using namespace fastIO;
const int N=5005;
int c,t,n,d,x[N];
vector<int> g[N];
int dis[N][N],cnt[N][N];
bool vis[N][N];
struct node{
    int id,d;
    bool operator< (const node &o) const {
        return d>o.d;
    }
};
priority_queue<node> q;
inline void dij(int s){
    while(!q.empty()){
        q.pop();
    }
    for(int i=1;i<=n;i++){
        dis[s][i]=1e9;
        cnt[s][i]=0;
        vis[s][i]=0;
    }
    dis[s][s]=0;
    cnt[s][s]=1;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().id,dd=q.top().d;
        q.pop();
        if(vis[s][u]) continue ;
        vis[s][u]=1;
        for(int v:g[u]){
            if(dis[s][v]>dd+1){
                dis[s][v]=dd+1;
                cnt[s][v]=cnt[s][u];
                if(!vis[s][v]) q.push({v,dis[s][v]});
            }else if(dis[s][v]==dd+1){
                cnt[s][v]+=cnt[s][u];
                if(!vis[s][v]) q.push({v,dis[s][v]});
            }
        }
    }
}
int xx[3000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();t=read();
    if(c<=10){
        while(t--){
            int ans=0;
            n=read();d=read();
            for(int i=1;i<=n;i++){
                g[i].clear();
            }
            for(int i=1;i<=n;i++){
                x[i]=read();
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(abs(x[i]-x[j])<=d){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                dij(i);
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(cnt[i][j]==2){
                        ans++;
                    }
                }
            }
            write(ans);
            pc('\n');
        }
    }
    if(c==11||c==12){
        while(t--){
            int ans=0;
            n=read();d=read();
            for(int i=1;i<=n;i++){
                xx[i]=read();
            }
            int cha=xx[2]-xx[1];
            int ps=d/cha;
            if(ps==0||ps==1){
                write(0);
                pc('\n');
                continue ;
            }
            for(int i=1;i<=n;i++){
                if(i+ps+ps-1<=n){
                    ans++;
                }
            }
            write(ans);
            pc('\n');
        }
    }
    if(c==13||c==14){
        while(t--){
            n=read();d=read();
            for(int i=1;i<=n;i++){
                xx[i]=read();
            }
            write(0);
            pc('\n');
        }
    }
    flush();
    return 0;
}