#include <bits/stdc++.h>
#define int long long
#define vector basic_string
#define pii array<int,2>
using namespace std;
int read(){
    int s=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        s=s*10+(ch-'0');
        ch=getchar();
    }
    return s*f;
}
bool St;
int c,n,m,d,q;
int head[500010],ne[500010],to[500010],w[500010],id;
int f[510][510],p[500010];
inline void add(int x,int y,int W){to[++id]=y,ne[id]=head[x],w[id]=W,head[x]=id;}
bool Ed;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) p[i]=read();
    for(int i=1,l,x,W;i<=n;i++){
        l=read();
        while(l--) x=read(),W=read(),add(x,i,W);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                f[i][j]=1e18;
    for(int i=1;i<=m;i++)
        for(int x=head[i];x;x=ne[x])
            for(int y=ne[x];y;y=ne[y])
                f[to[x]][to[y]]=min(f[to[x]][to[y]],w[x]+w[y]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            f[i][j]=f[j][i]=min(f[i][j],f[j][i]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x=read(),y=read(),ans=1e18;
        for(int i=head[x];i;i=ne[i])
            for(int j=head[y];j;j=ne[j])
                ans=min(ans,f[to[i]][to[j]]+w[i]+w[j]);
        printf("%lld\n",ans+p[x]+p[y]);
    }
    return 0;
}