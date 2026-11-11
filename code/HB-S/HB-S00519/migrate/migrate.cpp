#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n,f[N][2],g[N][2][3];
ll d,a[N],ans;
int nxt[N];
int solve(){
    scanf("%d%lld",&n,&d);ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=1;i<=n;i++){
        f[i][0]=1,f[i][1]=0;
        for(int j=0;j<2;j++)for(int k=0;k<3;k++)g[i][j][k]=0;
    }
    for(int i=1;i<=n;i++){
        nxt[i]=max(nxt[i-1],i);
        while(nxt[i]<n&&a[nxt[i]+1]-a[i]<=d)nxt[i]++;
    }
    for(int i=1;i<=n;i++)if(nxt[i]!=i){
        int r1=max(i,nxt[i-1]);
        int r2=(i<=2?i:max(i,nxt[i-2]));
        ans+=1ll*f[i][1]*(nxt[i]-i);
        ans+=1ll*g[i][0][0]*(r1-i);
        ans+=1ll*g[i][0][2]*(nxt[i]-r1);
        ans+=1ll*g[i][1][0]*(r1-r2);
        ans+=1ll*g[i][1][2]*(nxt[i]-r1);
        int len=nxt[i]-i;
        for(int j=0;j<2;j++){
            if(len==1)f[nxt[i]][j]+=f[i][j];
            else if(len==2)g[nxt[i]][0][j+j]+=f[i][j];
            else g[nxt[i]][1][j+j]+=f[i][j];
        }
        for(int j=0;j<2;j++)for(int k=0;k<3;k++)if(g[i][j][k]){
            int v0=(k==2)+1,v1=k+1,v2=j;
            if(len==1){
                int w=v0;
                if(r1==nxt[i])w+=v1;
                if(r2==nxt[i])w+=v2;
                if(w==1)f[nxt[i]][0]+=g[i][j][k];
                if(w==2)f[nxt[i]][1]+=g[i][j][k];
            }else{
                int w1=v0,w2=v0;
                if(r1==nxt[i])w1+=v1;
                if(r1>=nxt[i]-1)w2+=v1;
                if(r2==nxt[i])w1+=v2;
                if(r2>=nxt[i]-1)w2+=v2;
                if(w1==1){
                    if(w2==1)g[nxt[i]][len>2][0]+=g[i][j][k];
                    else g[nxt[i]][len>2][1]+=g[i][j][k];
                }
                if(w1==2)g[nxt[i]][len>2][2]+=g[i][j][k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;scanf("%*d%d",&t);
    while(t--)solve();
    return 0;
}