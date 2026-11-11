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
const int N=5e5+50;
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
int to[N],pool[N],n,m,appear[N],card[N];
ll ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read<int>(),m=read<int>();
    for(int i=1;i<=n;i++) card[i]=read<int>(),appear[i]=1;
    for(int i=n;i>=1;i--){
        if(!pool[card[i]]) to[i]=i+1,pool[card[i]]=i;
        else to[i]=pool[card[i]]+1;
    }
    for(int i=1;i<=n;i++) appear[to[i]]+=appear[i];
    for(int i=1;i<=n;i++) ans[card[i]]+=appear[i];
    for(int i=1;i<=m;i++){write<ll>(ans[i]);putchar(' ');}hh
    return 0;
}
/*
g++ card.cpp -o C -O2 -std=c++14 -Wall
./C

*/