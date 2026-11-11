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
    const int MAXN = 5e5+10;
    int n,m,a[MAXN];
    signed main(){
        read(n);read(m);
        for(int i = 1;i<=n;i++){
            read(a[i]);
        }
        sort(a+1,a+1+n);
        int L = 1,sum = 0;
        int res = 0;
        for(int i = 1;i<=n;i++){
            sum += a[i];
            while(a[i]*(i-L+1)-sum>m){
                sum -= a[L];
                L++;
            }
            res = max(res,i-L+1);
        }
        write(res,endl);
        return 0;
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T = 1;
    // gtx::read(T);
    while(T--) gtx::main();
    return 0;
}
/*
g++ crystal.cpp -o crystal -std=c++14 "-Wl,--stack=1000000000" -O2;if($?){echo "running";./crystal}
*/