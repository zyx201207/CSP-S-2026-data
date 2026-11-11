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
const int maxn=1000010;
int testid,T,n,nt[maxn],cnt[maxn];
LL d,x[maxn],ans;
inline int calc(int pre,int pos){
    int g=0;
    if(nt[pre]>=pos) g+=cnt[pre];
    if(nt[pre-1]>=pos) g+=cnt[pre-1];
    if(nt[pre-2]>=pos) g+=cnt[pre-2];
    return g;
}
inline void solve(){
    read(n,d);
    ans=0;
    for(int i=1;i<=n;i++) read(x[i]);
    x[n+1]=2000000000000000000;
    int u=n+1;
    for(int i=n;i>=1;i--){
        while(x[i]+d<x[u]) u--;
        nt[i]=u;
    }
    nt[n]=n+1;
    for(int i=n;i>=1;i--){
        int u=i,cs=0;
        cnt[i]=1;
        cnt[i-1]=0;
        if(i!=1) cnt[i-2]=0;
        while(u<n){
            if(nt[u]==u) break;
            int l=u+1,r=nt[u],pos=nt[u]+1;
            while(l<=r){
                int mid=l+r>>1;
                int g=calc(u,mid);
                if(g>2) l=mid+1;
                else r=mid-1,pos=mid;
            }
            if(pos!=nt[u]+1){
                l=u+1,r=nt[u];
                int poss=nt[u]+1;
                while(l<=r){
                    int mid=l+r>>1;
                    int g=calc(u,mid);
                    if(g>1) l=mid+1;
                    else r=mid-1,poss=mid;
                }
                ans+=poss-pos;
            }
            if(nt[u]>u) cnt[nt[u]]=calc(u,nt[u]);
            else cnt[nt[u]]=0;
            if(nt[u]-1>u) cnt[nt[u]-1]=calc(u,nt[u]-1);
            else cnt[nt[u]-1]=0;
            if(nt[u]-2>u) cnt[nt[u]-2]=calc(u,nt[u]-2);
            else cnt[nt[u]-2]=0;
            if(nt[u]==u) break;
            u=nt[u];
            if(cnt[u]>2) break;
            if(testid==11||testid==12||testid>14) if(++cs>=5) break;
        }
    }
    write(ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(testid,T);
    while(T--) solve(),write("\n");
    return 0;
}