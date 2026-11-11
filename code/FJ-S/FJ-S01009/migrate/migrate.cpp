#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll sum=0,f=1; char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-f;
    for(;'0'<=c&&c<='9';c=getchar()) sum=(sum<<1)+(sum<<3)+c-'0';
    return sum*f;
}
inline int Max(int x,int y){return x<y?y:x;}
/*-----------------*/
const int N=2e6+10;
int T,n,r[N];
ll d,x[N],f[N][3],g[N][3];
inline void solve(){
    n=read();d=read();
    for(int i=1;i<=n;i++) x[i]=read();
    for(int i=1;i<=n;i++) if(x[i]-x[1]<=d) r[1]=i;
    for(int i=2;i<=n;i++){
        r[i]=r[i-1];
        while(r[i]<n&&x[r[i]+1]-x[i]<=d) r[i]++;
    }
    // for(int i=1;i<=n;i++) printf("%d ",r[i]); putchar('\n');
    for(int i=1;i<=n;i++)
    for(int j=0;j<=2;j++) f[i][j]=g[i][j]=0;
    for(int i=n-1; i;i--){
        if(r[i]==i) continue;
        if(r[i]!=r[i-1]){
            f[i][2]+=f[r[i]][2]+r[i]-Max(r[i-1],i);
        }
        if(r[i]==i+1) f[i][0]=f[r[i]][0];
        else{
            int X=r[i]-2,Y=r[i]-1,Z=r[i];
            // printf(">> %d %d %d\n",X,Y,Z);
            // printf(">> %d %d %d\n",r[X],r[Y],r[Z]);
            f[i][0]=r[Y]-r[X];
            if(r[X]!=r[Z]){
                if(r[Y]==r[Z]) f[i][0]+=f[r[Y]][2];
                else f[i][0]+=f[Z][1];
            }
        }
        if(r[i-1]==r[i]) f[i][1]=0;
        else if(r[i-1]==r[i]-1) f[i][1]=f[r[i]][1];
        else f[i][1]=f[i][0];
        // printf("%lld %lld %lld\n",f[i][0],f[i][1],f[i][2]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=f[i][0];
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read();T=read();
    while(T--) solve();
    return 0;
}