#include<bits/stdc++.h>
using namespace std;
#define int long long
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
    const int MAXN = 2e6+10;
    int n,d,x[MAXN],r[MAXN],f[MAXN],g[MAXN],h[MAXN];
    signed main(){
        read(n);read(d);
        for(int i = 1;i<=n;i++){
            read(x[i]);
        }
        int R = n;
        int res = 0;
        for(int i = n;i;i--){
            while(x[R]-x[i]>d) R--;
            r[i] = R;
        }
        for(int i = n;i;i--){
            f[i] = g[i] = h[i] = 0;
            if(r[i]-r[i-1]>=2) f[i] = f[r[i]];
            else if(r[i]-r[i-1]==1) f[i] = g[r[i]];
            else if(r[i-2]!=r[i]&&r[i]!=i) f[i] = h[r[i]];
            f[i] += r[i-1]-max(i,r[i-2]);
            if(r[i]==max(r[i-1],i)) g[i] = 0;
            else if(r[i]==max(r[i-1],i)+1) g[i] = g[r[i]];
            else if(r[i]>=max(r[i-1],i)+2) g[i] = f[r[i]];
            if(r[i]==max(i,r[i-1])) h[i] = 0;
            else if(r[i]>max(i,r[i-1])) h[i] = h[r[i]];
            h[i] += r[i]-max(i,r[i-1]);
            if(r[i]==i) res += 0;
            else if(r[i]==i+1) res += g[r[i]];
            else if(r[i]>=i+2) res += f[r[i]];
        }
        write(res,endl);
        return 0;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T = 1;
    gtx::read(T);
    gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ migrate.cpp -o migrate -std=c++14 "-Wl,--stack=1000000000" -O2;if($?){echo "running";./migrate}


何意味？三道题都一边过大样例？
*/