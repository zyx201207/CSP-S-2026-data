#include<bits/stdc++.h>
using namespace std;
#define int long long
int fw,t;
int a,b;
struct m{
    int v,next;
}edge[1000005];
int head[1000005],cnt;
void add(int x,int y){
    edge[++cnt]={y,head[x]};
    head[x]=cnt;
}
int dep[1000005],fa[1000005];
int LCA(int x,int y){
    while(1){
        if(x==y)return x;
        if(dep[x]<dep[y])swap(x,y);
        if(dep[x]>dep[y]){
            x=fa[x];
        }else{
            x=fa[x];
            y=fa[y];
        }
    }
}
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    fa[x]=f;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].v;
        if(v==f)continue;
        dfs(v,x);
    }
}
int DIS(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int vis[1000005],ans,fl[100005];
void fld(int x,int f){
    fl[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].v;
        if(v==f||vis[v]==0)continue;
        fld(v,x);
    }
}
void dp(int x,int cnt){
    //printf("%lld ",x);
    if(x==a+1){
        if(cnt!=b)return ;
        for(int i=1;i<=a;i++){
            fl[i]=0;
        }
        int flc=0;
        for(int i=1;i<=a;i++){
            if(vis[i]==0||fl[i]==1)continue;
            flc++;
            fld(i,0);
        }
        if(flc>2)return ;
        int re=0;
        for(int i=1;i<=a;i++){
            //printf("%lld ",vis[i]);
            int Hs=1e18;
            for(int j=1;j<=a;j++){
                if(vis[j]==0)continue;
                Hs=min(DIS(i,j),Hs);
            }
            re=max(re,Hs);
        }
        //printf(" %lld\n",re);
        ans=min(ans,re);
        return ;
    }
    vis[x]=1;
    dp(x+1,cnt+1);
    vis[x]=0;
    dp(x+1,cnt);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld %lld",&fw,&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        cnt=0;
        for(int i=1;i<=a;i++){
            head[i]=0;
        }
        for(int i=1;i<a;i++){
            int l,r;
            scanf("%lld %lld",&l,&r);
            add(l,r);
            add(r,l);
        }
        ans=1e18;
        dfs(1,0);
        dp(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
