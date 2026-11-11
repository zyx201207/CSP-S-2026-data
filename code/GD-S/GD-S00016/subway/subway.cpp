#include<bits/stdc++.h>
using namespace std;
int testid,n,m,d,q;
long long intin[500001];
long long f[501][501];
int e1[500001][21];
long long e2[500001][21];//line,dis
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(long long x){
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cin>>testid>>n>>m>>d>>q;
    testid=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)intin[i]=read();
    for(int i=1;i<=n;i++){
        int cnt=read();
        while(cnt--){
            int x=read(),y=read();
            //e[x].push_back({i,y});
            e1[x][++e1[x][0]]=i;
            e2[x][e1[x][0]]=y;
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=e1[i][0];j++){
            for(int k=1;k<=e1[i][0];k++){
                f[e1[i][j]][e1[i][k]]=min(f[e1[i][j]][e1[i][k]],e2[i][j]+e2[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x=read(),y=read();
        long long ans=1e18;
        for(int i=1;i<=e1[x][0];i++){
            for(int j=1;j<=e1[y][0];j++){
                ans=min(ans,e2[x][i]+e2[y][j]+f[e1[x][i]][e1[y][j]]);
            }
        }
        write(ans+intin[x]+intin[y]),putchar('\n');
    }
    return 0;
}
//kachang if you have enough time