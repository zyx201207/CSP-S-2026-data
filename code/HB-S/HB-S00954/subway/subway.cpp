#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int t[505][N],w[N],q,m,n,d,c,a[505][N],x[N],y[N];
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=n;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=read();t[i][j]=read();
        }
    }
    for(int i=1;i<=q;i++)x[i]=read(),y[i]=read();
    
    return 0;
}