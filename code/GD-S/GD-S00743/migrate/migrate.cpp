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
int c,t,n,a[2000010],k,pr[2000010],ne[2000010],f[2000010],g[2000010],ans;
void solve(){
    n=read(),k=read(),ans=0;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1,j=1;i<=n;i++){
        while(j+1<=n&&a[j+1]<=a[i]+k) j++;
        ne[i]=j;
    }
    for(int i=1,j=1;i<=n;i++){
        while(j<=n&&a[j]<a[i]-k) j++;
        pr[i]=j;
    }
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    for(int i=1;i<=n;i++) g[pr[i]]++;
    for(int i=1,j=0;i<=n;i++){
        while(j<ne[i]) g[pr[++j]]--;
        if(ne[i]-1>i) ans+=g[ne[i]-1];
    }
    for(int i=1;i<=n;i++) f[i]=g[i]=0;
    for(int i=1;i<=n;i++) f[ne[i]]++,g[pr[i]]++;
    for(int i=1;i<=n;i++)
        if(pr[ne[i]]==i)
            f[ne[i]]+=f[i];
    for(int i=n;i;i--)
        if(ne[pr[i]]==i)
            g[pr[i]]+=g[i];
    for(int i=1,u,v;i<=n;i++){
        u=i,v=ne[ne[i]];
        if(pr[pr[v]]<u){
            if(pr[v]+1!=ne[u]||pr[v]<=u) continue;
            ans+=g[v];
        }
    }
    for(int i=1,u,v;i<=n;i++){
        u=pr[pr[i]],v=i;
        if(ne[ne[u]]>v){
            if(pr[v]+1!=ne[u]||ne[u]>=v) continue;
            ans+=f[u];
        }
    }
    for(int i=1,u,v,pl;i<=n;i++){
        u=i,v=ne[ne[i]];
        if(pr[pr[v]]!=u) continue;
        if(pr[v]+1!=ne[u]) continue;
        if(ne[u]>=v||pr[v]<=u) continue;
        ans+=(f[u]+1)*(g[v]+1)-1;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--) solve();
    return 0;
}