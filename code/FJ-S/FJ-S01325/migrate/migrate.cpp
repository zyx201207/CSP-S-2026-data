#include<bits/stdc++.h>
const int N=2e6;
int caseid,Tcase;
int n;
long long d,p[N+5];
long long read(){
    char c=getchar();long long x=0,f=1;
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
int nxt[N+5],pre[N+5];
long long ans;
int f[N+5],g[N+5];
int spr[N+5],snt[N+5];
void clean(){}
void work(){
    n=read(),d=read();
    for(int i=1;i<=n;++i)p[i]=read(),spr[i]=snt[i]=0;
    nxt[n]=n;
    for(int i=n-1;i;--i){
        nxt[i]=nxt[i+1];
        while(p[nxt[i]]-p[i]>d)--nxt[i];
        //printf("%d %lld %lld\n",i,p[i],p[nxt[i]]);
    }
    pre[1]=1;
    for(int i=2;i<=n;++i){
        pre[i]=pre[i-1];
        while(p[i]-p[pre[i]]>d)++pre[i];
    }
    for(int i=1;i<=n;++i){
        //printf("%d\n",nxt[i]);
        if(pre[i]!=i)spr[pre[i]]++;
        if(nxt[i]!=i)snt[nxt[i]]++;
    }
    ans=0;
    for(int i=n;i;--i){
        f[i]=spr[i]+1;
        if(nxt[i]!=i&&pre[nxt[i]]==i)f[i]+=f[nxt[i]]-1;
    }
    for(int i=1;i<=n;++i){
        g[i]=snt[i]+1;
        if(pre[i]!=i&&nxt[pre[i]]==i)g[i]+=g[pre[i]]-1;
    }
    ans=0;
    for(int i=1;i<n;++i){
        int sr=spr[i];
        if(pre[i+1]==i)--sr;
        //printf("%d\n",sr);
        if(nxt[i+1]!=i+1&&pre[nxt[i+1]]==i){
            sr+=f[nxt[i+1]]-1;
        }
        int sl=snt[i+1];
        if(nxt[i]==i+1)--sl;
        if(pre[i]!=i&&nxt[pre[i]]==i+1){
            sl+=g[pre[i]]-1;
        }
        //printf("%d %d %d\n",i,sl,sr);
        ans+=1ll*sl*sr;
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    caseid=read(),Tcase=read();
    while(Tcase--){
        clean();
        work();
    }
    return 0;
}