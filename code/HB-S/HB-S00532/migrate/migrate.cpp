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
#define mp(x,y) make_pair(x,y)
const int N=2e6+50;
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
int cid,t,n,l[N],r[N],cnt[N],sonl[N],sonr[N];ll d,a[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cid=read<int>(),t=read<int>();
    while(t--){
        n=read<int>(),d=read<ll>(),ans=0ll;
        for(int i=1;i<=n;i++) a[i]=read<ll>();
        l[1]=0;
        for(int i=2;i<=n;i++){
            int L=1,R=i-1,mid;l[i]=0;
            while(L<=R){
                mid=(L+R)>>1;
                if(a[i]-a[mid]<=d) l[i]=mid,R=mid-1;
                else L=mid+1;
            }
        }
        r[n]=0;
        for(int i=1;i<n;i++){
            int L=i+1,R=n,mid;r[i]=0;
            while(L<=R){
                mid=(L+R)>>1;
                if(a[mid]-a[i]<=d) r[i]=mid,L=mid+1;
                else R=mid-1;
            }
        }
        for(int i=1;i<n;i++){
            if(l[i]==0){sonl[i]=1;continue ;}
            int tl=l[i];
            if(!tl||a[i+1]-a[tl]<=d){sonl[i]=1;continue ;}
            int L=tl+1,R=i-1,mid,tans=tl;
            while(L<=R){
                mid=(L+R)>>1;
                if(a[i+1]-a[mid]>d) tans=mid,L=mid+1;
                else R=mid-1;
            }
            sonl[i]=tans-tl+1+sonl[tl];
        }
        for(int i=n;i>1;i--){
            if(r[i]==0){sonr[i]=1;continue ;}
            int tr=r[i];
            if(!tr||a[tr]-a[i-1]<=d){sonr[i]=1;continue ;}
            int L=i+1,R=tr-1,mid,tans=tr;
            while(L<=R){
                mid=(L+R)>>1;
                if(a[mid]-a[i-1]>d) tans=mid,R=mid-1;
                else L=mid+1;
            }
            sonr[i]=tr-tans+1+sonr[tr];
        }
        //for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<" "<<sonl[i]<<" "<<sonr[i]<<endl;
        for(int i=1;i<=n+1;i++) cnt[i]=0;
        int ptr=n;
        for(int x=n-1;x>=1;x--){
            while(ptr>x&&a[ptr]-a[x]>d) cnt[l[ptr]]++,ptr--; 
            if(r[x]!=0){
                ll ans1,ans2;
                int y=r[r[x]];
                if(l[r[x]-1]!=x) ans1=1;
                else ans1=sonl[x];
                if(y&&r[x]==l[y]+1) ans2=sonr[y]+cnt[r[x]-1]-1;
                else ans2=cnt[r[x]-1];
                //cout<<x<<" "<<ans1<<" "<<ans2<<" "<<y<<endl;
                ans+=ans1*ans2;
            }
        }
        write<ll>(ans);hh
    }
    return 0;
}
/*
g++ migrate.cpp -o M -O2 -std=c++14 -Wall
./M
time ./M

*/