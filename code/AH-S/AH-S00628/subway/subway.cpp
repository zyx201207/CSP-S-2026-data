#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+c-48;c=getchar();}return f*x;}
const int N=5e5+5;
int _,n,m,_2,Q;
int w[N];
int s[N],t[N];
struct node{
    int to,w;
};
vector<node>e[N];
vector<int>g[N];
int ans[100005],d[N],vis[N];
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> >q;
void dij(int s){
    q.push(make_pair(0,s));
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    d[s]=0;
    while(!q.empty()){
        int top=q.top().second;q.pop();
        if(vis[top])continue;
        vis[top]=1;
        for(auto i:e[top]){
            if(d[i.to]>d[top]+i.w){
                d[i.to]=d[top]+i.w;
                if(!vis[i.to])q.push({d[i.to],i.to});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    _=read(),m=read(),n=read(),_2=read(),Q=read();
    rep(i,1,n)w[i]=read();
    rep(i,1,m){
        int k=read();
        rep(j,1,k)
            s[j]=read(),t[j]=read();
        rep(j,1,k){
            rep(l,j+1,k){
                e[s[j]].push_back({s[l],t[j]+t[l]});
                e[s[l]].push_back({s[j],t[j]+t[l]});
            }
        }
    }
    rep(i,1,Q){
        s[i]=read(),t[i]=read();
        g[s[i]].push_back(i);
    }
    rep(i,1,Q){
        if(!ans[i]){
            dij(s[i]);
            for(auto j:g[s[i]]){
                //printf("%lld %lld:%lld",s[i],t[j],d[t[j]]);
                ans[j]=d[t[j]]+w[s[i]]+w[t[j]];
            }

        }
    }
    rep(i,1,Q)printf("%d\n",ans[i]);
    return 0;
}
