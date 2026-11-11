#include<bits/stdc++.h>
#define space putchar(' ');
#define endl putchar('\n');
#define debug puts("------------")
#define int long long
using namespace std;
inline int read();
inline void write(int x);
const int N=2E6+5;
int a[N],sum,d,n,minn;

inline void ds(int now,int v,int cnt){
    if(now==v){
        minn=min(minn,cnt);
        return;
    }
    for(int i=now+1;i<=v;i++){
        if(a[i]-a[now]<=d) ds(i,v,cnt+1);
    }
    return;
}

inline void dfs(int now,int v,int cnt){
    if(now==v){
        sum+=(cnt==minn);
        return;
    }
    for(int i=now+1;i<=v;i++){
        if(a[i]-a[now]<=d) dfs(i,v,cnt+1);
    }
    return;
}
inline void solve(){
    n=read();d=read();
    int ans=0;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=0;minn=0x3f3f3f3f3f3f3f3f;
            ds(i,j,0);
            dfs(i,j,0);
            ans+=(sum==2);
        }
    }
    write(ans);endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    while(T--) solve();
    return 0;
}
inline int read(){
    int sgn=0,ret=0,ch=getchar();
    while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return sgn?-ret:ret;
}
inline void W(int x){
    if(x>9) W(x/10);
    putchar(x%10+'0');
    return;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    W(x);
    return;
}

//Oct31==Dec25?
