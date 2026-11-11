#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
namespace gtx{
    char*p1,*p2,buf[1<<21];
    #define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
    void read(int&x){
        x=0;char ch;int h = 1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x *= h;
    }
    void write(int x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]] = x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void read(char&x){do x=getchar();while(x==' '||x=='\n'||x=='\r');}
    void write(char x){putchar(x);}
    void write(int x,char y){write(x);write(y);}
    #ifndef int
    void read(long long&x){
        x=0;char ch;int h = 1;
        do{ch=getchar();if(ch=='-')h=-h;}while(!isdigit(ch));
        while(isdigit(ch)) x*=10,x+=ch-'0',ch=getchar();
        x *= h;
    }
    void write(long long x){
        if(x<0) putchar('-'),x=-x;
        int st[35]={};
        do st[++st[0]] = x%10,x/=10;while(x);
        while(st[0]) putchar(st[st[0]--]+'0');
    }
    void write(long long x,char y){write(x);write(y);}
    #endif
    const int MAXN = 510;
    const int MAXM = 5e5+10;
    int c,n,m,d,q; 
    long long dis[MAXN][MAXN];
    int to[MAXM][21],t[MAXM][21];
    int w[MAXM];
    signed main(){
        read(c);read(n);read(m);read(d);read(q);
        for(int i = 1;i<=m;i++){
            read(w[i]);
        }
        for(int i = 1;i<=n;i++){
            int k;
            read(k);
            while(k--){
                int x,y;
                read(x);read(y);
                to[x][++to[x][0]] = i;
                t[x][to[x][0]] = y;
            }
        }
        memset(dis,0x3f,sizeof dis);
        for(int i = 1;i<=n;i++){
            dis[i][i] = 0;
        }
        for(int i = 1;i<=m;i++){
            for(int a = 1;a<=to[i][0];a++){
                for(int b = a+1;b<=to[i][0];b++){
                    dis[to[i][a]][to[i][b]] =
                    dis[to[i][b]][to[i][a]] = 
                    min(dis[to[i][a]][to[i][b]],0ll+t[i][a]+t[i][b]);
                }
            }
        }
        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            read(x);read(y);
            long long res = 0x3f3f3f3f3f3f3f3f;
            for(int i = 1;i<=to[x][0];i++){
                for(int j = 1;j<=to[y][0];j++){
                    res = min(res,0ll+t[x][i]+t[y][j]+dis[to[x][i]][to[y][j]]+w[x]+w[y]);
                }
            }
            write(res,endl);
        }
        return 0;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T = 1;
    // gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 "-Wl,--stack=1000000000" -O2;if($?){echo "running";./subway}
*/