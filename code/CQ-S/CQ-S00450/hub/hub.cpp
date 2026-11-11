#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1<<21],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=gtchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return x;
}
int t,n,k,ans,deep[1000005],fa[1000005],si[1000005],mx[1000005],top[1000005],in[1000005],out[1000005],cnt,p[1000005],num[1000005];
pair<int,int> maxn[1000005],maxx[1000005],maxy[1000005],maxo[1000005],di[1000005],dn[1000005],dx[1000005],du[1000005];
vector<int> g[1000005];
inline int jump(int v,int u,int k){
    if(deep[v]<deep[u]) swap(u,v);
    k=deep[v]-k;
    while(deep[top[v]]>k) v=fa[top[v]];
    return p[k-deep[top[v]]+in[top[v]]];
}
inline int lca(int u,int v){
    while(top[u]!=top[v]) deep[top[u]]>deep[top[v]]?u=fa[top[u]]:v=fa[top[v]];
    return deep[u]<deep[v]?u:v;
}
void dfs1(int v,int f){
    fa[v]=f,deep[v]=f?deep[f]+1:0,maxx[v]=maxy[v]=maxn[v]=make_pair(deep[v],v),si[v]=1,mx[v]=0;
    for(int i:g[v]){
        if(i!=f){
            dfs1(i,v),si[v]+=si[i],mx[v]=si[i]>si[mx[v]]?i:mx[v];
            if(maxn[i]>maxn[v]) maxy[v]=maxx[v],maxx[v]=maxn[v],maxn[v]=maxn[i];
            else if(maxn[i]>maxx[v]) maxy[v]=maxx[v],maxx[v]=maxn[i];
            else maxy[v]=max(maxy[v],maxn[i]);
        }
    }
}
void dfs2(int v,int t){
    top[v]=t,in[v]=++cnt,p[cnt]=v,dn[v]=dx[v]=make_pair(0,0);
    if(mx[v]){
        dfs2(mx[v],t);
        for(int i:g[v]){
            if(i!=fa[v]&&i!=mx[v]) dfs2(i,i);
            if(i!=fa[v]){
                if(di[i]>dn[v]) dx[v]=dn[v],di[v]=di[i];
                else dx[v]=max(dx[v],di[i]);
            }
        }
    }
    int tmp=maxn[v].first+maxx[v].first-2*deep[v];
    out[v]=cnt,di[v]=max(make_pair(tmp,jump(maxn[v].second,maxx[v].second,tmp/2)),dn[v]);
}
inline pair<int,int> operator-(pair<int,int> x,int y){
    return make_pair(x.first-y,x.second);
}
void dfs3(int v){
    maxo[v].first++;
    for(int i:g[v]){
        if(i==fa[v]) continue;
        pair<int,int> x=(maxn[i]==maxn[v]?maxx[v]:maxn[v])-deep[v],y=(maxn[i]==maxn[v]||maxn[i]==maxx[v]?maxy[v]:maxn[v])-deep[v];
        if(maxo[v]>x) y=x,x=maxo[v];
        else y=max(maxo[v],y);
        int tmp=x.first+y.first;
        du[i]=max(max(du[v],di[i]==dn[v]?dx[v]:dn[v]),make_pair(tmp,jump(x.second,y.second,tmp/2))),maxo[i]=x,dfs3(i);
    }
}
int dfs4(int v,int f,int x){
    int res=0;
    for(int i:g[v]) if(i!=x&&i!=f) res=max(res,dfs4(i,v,x)+1);
    return num[f?res:n]++,res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    read(),t=read();
    while(t--){
        n=read(),k=read(),ans=0x3f3f3f3f,cnt=0;
        for(int i=1,x,y;i<n;i++) x=read(),y=read(),g[x].emplace_back(y),g[y].emplace_back(x);
        dfs1(1,0),dfs2(1,1),maxo[1]=make_pair(-1,0),dfs3(1);
        if(k==n) ans=0;
        else if(k==2) for(int i=2;i<=n;i++) ans=min(ans,(max(di[i].first,du[i].first)+1)/2);
        else{
            for(int i=2;i<=n;i++){
                dfs4(di[i].second,0,fa[i]),dfs4(du[i].second,0,i);
                int j=n,sum=0;
                while(sum<=k) sum+=num[j--];
                ans=min(ans,j+2);
                for(j=0;j<=n;j++) num[j]=0;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}