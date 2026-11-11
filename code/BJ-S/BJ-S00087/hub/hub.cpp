#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,head[200],lnum,fa[200],dis[200];
queue<int> qu;
int find(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
struct line{
    int to,nxt;
}l[300];
void link(int from,int to){
    l[++lnum]={to,head[from]};
    head[from]=lnum;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%*d %lld",&t);
    while(t--){
        lnum=0;
        scanf("%lld %lld",&n,&m);
        for(int i=1;i<=n;i++){
            head[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%lld %lld",&u,&v);
            link(u,v);
            link(v,u);
        }
        int ans=4e18;
        for(int i=0;i<(1ll<<n);i++){
                //printf("%lld %lld %lld %d\n",i,__builtin_popcountll(i),m,__builtin_popcountll(i)!=m);
            if(__builtin_popcountll(i)!=m){
                continue;
            }
            for(int j=1;j<=n;j++){
                fa[j]=j;
            }
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    for(int k=head[j];k;k=l[k].nxt){
                        if((i>>(l[k].to-1))&1){
                            int fx=find(j),fy=find(l[k].to);
                            if(fx==fy){
                                continue;
                            }
                            fa[fx]=fy;
                        }
                    }
                }
            }
            set<int> st;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    st.insert(find(j));
                }
            }
            if(st.size()>2){
                continue;
            }
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    dis[j]=0;
                    qu.push(j);
                }
                else{
                    dis[j]=4e18;
                }
            }
            int res=0;
            while(!qu.empty()){
                int qtop=qu.front();
                qu.pop();
                for(int j=head[qtop];j;j=l[j].nxt){
                    if(dis[l[j].to]>dis[qtop]+1){
                        dis[l[j].to]=dis[qtop]+1;
                        qu.push(l[j].to);
                    }
                }
            }
            for(int j=1;j<=n;j++){
                res=max(res,dis[j]);
            }
            ans=min(ans,res);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
