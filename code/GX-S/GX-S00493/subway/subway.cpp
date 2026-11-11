#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s[1009][1009],way[200009],t[200009],w[200009];
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void out(ll x){
    if(x<0){
        putchar('-');
        out(-x);
        return ;
    }
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            s[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            way[j]=read(),t[j]=read();
        }
        for(int j=1;j<=k-1;j++){
            for(int u=j+1;u<=k;u++){
                ll u1=way[j],v1=way[u];
                s[u1][v1]=min(s[u1][v1],t[j]+t[u]);
                s[v1][u1]=min(s[v1][u1],t[j]+t[u]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        x=read(),y=read();
        out(s[x][y]+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}
