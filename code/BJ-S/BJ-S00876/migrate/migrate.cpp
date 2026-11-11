#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=5000+5;
long long f[M][M];
long long x[N];
/*
bool check(int l,int r){
    for (int u=l;u<=r;u++){
        for (int i=l;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if ((x[j]-x[i])<=d) f[i][j]=1;
                else break;
            }
        }
        //k V
        for (int i=l;i<=r;i++){
            for (int j=i+1;j<=r;j++){
                for (int k=i;k<=j;k++){
                    h[i][j]=min(h[i][j],h[i][k]+h[k][j]);
                }
            }
        }
        //k x
        for (int i=l;i<=r;i++){
            for (int j=i+1;j<=r;j++){
                for (int k=i;k<=j;k++){
                    if (k==u) continue;
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }

        if (h[l][r]==g[l][r]) return true;
    }
    return false;
}
void DFS(int st,int now,int step){
    vis[step]=now;
    for (int i=1;i<=n;i++){
        if (i==step) continue;
        if (abs(x[i]-x[now])<=d){
            DFS(i,step+1);
        }
    }

}
*/
long long ans;
bool g[M][M];
void work(){
    ans=0;
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
    memset(f,0x3f,sizeof f);
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if ((x[j]-x[i])<=d) f[i][j]=1;
            else break;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            for (int k=i;k<=j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){

        }
    }
    for (int l=1;l<=n;l++){
        for (int r=l+1;r<=n;r++){
            ans+=g[l][r];
        }
    }
    printf("%lld\n",ans);
}
bool vis[N];
void solve1(){
    ans=0;
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
    int o=x[2]-x[1];
    int x=d/o;
    if (x==1){
        printf("0\n");
        return ;
    }
    memset(vis,true,sizeof vis);
    vis[1]=false;
    for (int i=2;i<=x;i++){
        if (vis[i]) for (int j=1;i*j<=n-1;j++) vis[i*j]=false;
    }
    for (int i=1;i<=n-1;i++) ans+=vis[i]*(n-i);
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for (int i=1;i<=t;i++) solve1();
    //if (c==11 || c==12) for (int i=1;i<=t;i++) solve1();
    //else for (int i=1;i<=t;i++) work();
    return 0;
}
