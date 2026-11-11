#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define hh putchar(10);
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define mids (nl+nr)>>1
#define set_it set<int>::iterator
#define map_it map<int,int>::iterator
#define LLM (ll)1e17
#define IM (int)1e9
#define Re(x) qpow(x,mod-2)
#define mp(x,y) make_pair(x,y)
const int N=2e5+50;
template<class T>
inline T read(){
    T x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
template<class T>
inline void write(T ans){
    if(ans<0){putchar('-');write<T>(-ans);}
    else if(ans<10) putchar(ans+'0');
    else{write<T>(ans/10);putchar(ans%10+'0');}
    return ;
}
int a[N],ptl,ptr,n;char c[N];
ll ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read<int>();
    for(int i=1;i<=n;i++){
        a[i]=read<int>();
        c[i]=getchar();
        while(c[i]<'a'||c[i]>'z') c[i]=getchar();
    }
    ptl=1,ptr=n;
    while(ptl<ptr){
        int tmp=min(a[ptl],a[ptr]);
        if(c[ptl]!=c[ptr]) ans+=tmp;
        a[ptl]-=tmp,a[ptr]-=tmp;
        if(!a[ptl]) ptl++;
        if(!a[ptr]) ptr--;
    }
    write<ll>(ans);hh
    return 0;
}
/*
g++ string.cpp -o S -O2 -std=c++14 -Wall
./S

*/