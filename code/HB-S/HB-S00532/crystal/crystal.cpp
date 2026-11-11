#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ill __int128
#define hh putchar(10);
#define lc(k) st[k].lc
#define rc(k) st[k].rc
#define LLM (ll)1e17
#define IM (int)1e9
#define mids (nl+nr)>>1
#define set_it set<int>::iterator
#define map_it map<int,int>::iterator
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
ll a[N],pre[N],m;
int n;
bool check(int mid){
    for(int i=mid;i<=n;i++){
        if(1ll*mid*a[i]-pre[i]+pre[i-mid]<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read<int>(),m=read<ll>();
    for(int i=1;i<=n;i++) a[i]=read<ll>();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    int l=1,r=n,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    write<int>(ans);hh
    return 0;
}
/*
g++ crystal.cpp -o C -O2 -std=c++14 -Wall
./C
time ./C

*/