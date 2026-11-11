#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T>inline void read(T&x){
        x=0;char c=getchar();bool f=0;
        while(!isdigit(c)) f|=(c=='-'),c=getchar();
        while(isdigit(c)) x=x*10-(c-'0'),c=getchar();
        !f?(x=-x):0;
    }
    template<typename T>inline void write(T x){
        if(x==0){putchar('0');return ;}
        if(x>0) x=-x;
        else putchar('-');
        int st[20],top=0;
        while(x) st[++top]=x%10,x/=10;
        while(top) putchar('0'-st[top--]);
    }
    inline void read(char&x){x=getchar();while(isspace(x)) x=getchar();}
    inline void write(char x){putchar(x);}
    inline void read(string&s){
        s.clear();char c;read(c);
        while(!isspace(c)&&~c) s+=c,c=getchar();
    }
    inline void write(string s){for(int i=0,len=s.size();i<len;i++) putchar(s[i]);}
    template<typename T>inline void write(T*x){while(*x) putchar(*x++);}
    template<typename T,typename...T2>inline void read(T&x,T2&...y){read(x),read(y...);}
    template<typename T,typename...T2>inline void write(const T&x,const T2&...y){write(x),putchar(' '),write(y...),sizeof...(y)==1?putchar('\n'):0;}
}using namespace IO;
#define LL long long
const int maxn=500010;
int n,out;
LL m,a[maxn],sum[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,ans=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid-1,ans=mid;
            else l=mid+1;
        }
        out=max(out,i-ans+1);
    }
    write(out);
    return 0;
}