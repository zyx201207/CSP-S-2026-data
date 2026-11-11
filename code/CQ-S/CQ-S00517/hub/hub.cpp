#include<bits/stdc++.h>
#define int long long
#define il inline
#define co const
#define re register
using namespace std;
il int read();
co int N=1e6+10;
struct noid{
    int d,nxt;
}g[N*2];
int head[N],cnt=0;
bitset<N> v;
il void add(co int x,co int y){
    g[++cnt]={y,head[x]};
    head[x]=cnt;
}
il void lt(co int x,co int s){ 
    v[x]=1;
    for(re int i=head[x];i;i=g[i].nxt){
        co int xx=g[i].d;
        if(v[xx]||!(s>>(xx-1)&1))continue;
        lt(xx,s);
    }
}
il int dfs(co int x,co int fa,co int s){
    if(s>>(x-1)&1)return 0;
    int ans=1e18;
    for(re int i=head[x];i;i=g[i].nxt){
        co int xx=g[i].d;
        if(fa==xx)continue;
        ans=min(ans,dfs(xx,x,s)+1);
    }
    return ans;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0); 
    // cout.tie(0);
    int bh=read(),T=read();
    // cin>>bh>>T;
    while(T--){
        co int n=read(),k=read();
        cnt=0;
        for(re int i=1;i<=n;++i){
            head[i]=0;
        }
        for(re int i=1;i<n;++i){
            co int x=read(),y=read();
            add(x,y);
            add(y,x);
        }
        int ans=1e18;
        for(re int s=0;s<1<<n;++s){
            if(__builtin_popcount(s)!=k)continue;
            // cout<<s<<' ';
            for(re int i=1;i<=n;++i)v[i]=0;
            int gs=0;
            for(re int i=1;i<=n;++i){
                if((s>>(i-1)&1)&&!v[i]){
                    lt(i,s);
                    ++gs;
                }
            }
            // cout<<s<<' '<<gs<<'\n';
            if(gs>2)continue;
            int maxx=0;
            for(re int i=1;i<=n;++i){
                if(!(s>>(i-1)&1)){
                    // cout<<dfs(i,0,s)<<' ';
                    maxx=max(maxx,dfs(i,0,s));
                }
            }
            // cout<<maxx<<'\n';
            ans=min(ans,maxx);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
il int read(){
    int ans=0;
    bool op=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')op=1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    if(op)return -ans;
    return ans;
}