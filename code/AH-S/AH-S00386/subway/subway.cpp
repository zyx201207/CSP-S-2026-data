#include<bits/stdc++.h>
using namespace std;
long long read(){
    long long x=0;
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-'){
        f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    return x*f;
}
long long n,m,d,q,w[500005],f[505][505],ans;
vector<long long>a[500005],t[500005];
int main(){
//    system("diff subway7.ans subway.out");
//    return 0;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    n=read();
    n=read();
    m=read();
    d=read();
    q=read();
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1,k,x,tt;i<=n;i++){
        k=read();
        for(int j=1;j<=k;j++){
            x=read();
            tt=read();
            a[x].push_back(i);
            t[x].push_back(tt);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<a[i].size();k++){
                f[a[i][j]][a[i][k]]=min(f[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1,x,y;i<=q;i++){
        ans=1e18;
        x=read();
        y=read();
        for(int j=0;j<a[x].size();j++){
            for(int k=0;k<a[y].size();k++){
                ans=min(ans,f[a[x][j]][a[y][k]]+t[x][j]+t[y][k]);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}

