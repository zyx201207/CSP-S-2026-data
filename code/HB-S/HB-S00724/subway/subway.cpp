#include<bits/stdc++.h>
using namespace std;

#define int long long
int f[400+100][400+100];

int read() {
    int x=0,pp=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') pp=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*pp;
}

void write(int x) {
    if(x<0) {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

const int maxn=(5e5+100);
int C,n,m,D,q;
int w[maxn];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    C=read(),n=read(),m=read(),D=read(),q=read();

    for(int i=1;i<=m;i++) {
        w[i]=read();
        for(int j=1;j<=n;j++) w[i+m*j]=w[i];
    }
    //cout<<w[8]<<' '<<00000;

    for(int i=1;i<=410+10;i++)
        for(int j=1;j<=410+10;j++) {
            f[i][j]=2e9;
            if(i==j) f[i][j]=0;
        }

    for(int i=1;i<=n;i++) {
        int T;T=read();
        int pa;
        for(int j=1;j<=T;j++) {
            int a,t;
            a=read(),t=read();
            if(j!=1) {
                f[pa][a+m*(i-1)]=0;
                f[a+m*(i-1)][pa]=0;
            }
            pa=a+m*(i-1);
            w[pa]+=t;
            //cout<<pa<<' ';
            for(int k=1;k<=n;k++) {
                int u=a+(k-1)*m;
                if(u!=pa) {
                    if(f[pa][u]==2e9) f[pa][u]=t;
                    else f[pa][u]+=t;

                    if(f[u][pa]==2e9) f[u][pa]=t;
                    else f[u][pa]+=t;
                }
            }
            //cout<<"\n";
        }
    }

    for(int k=1;k<=400+10;k++)
        for(int i=1;i<=400+10;i++)
            for(int j=1;j<=400+10;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

    while(q--) {
        int x,y;
        x=read(),y=read();
        int ans=1e17+10;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=min(ans,f[x+(j-1)*m][y+(i-1)*m]+w[x+(j-1)*m]+w[y+(i-1)*m]);
        write(ans);
        cout<<"\n";
    }
   // cout<<f[1][8]<<' '<<w[8];

    return 0;
}
