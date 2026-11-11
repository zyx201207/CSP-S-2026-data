#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=(j);i<=(n);i++)
#define F(i,n,j) for(int i=(n);i>=(j);i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define pri_grt(x) x,vector<x>,greater<x>
#define arr(x) array<int,x>
#define arrl(x) array<ll,x>
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    #define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin)),p1==p2?EOF:*p1++)
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+(c-'0'),c=gc();
        return ak*csp;
    }
}
using fsd::read;
const int N=2e6+10;
#define NXD
int n,D;
int x[N];
int nx[N],pr[N];
int bck[N],frt[N],bck1[N];
int pre[N],suf[N];
void gs(){
    n=read(),D=read();
    f(i,1,n)x[i]=read();
    int s=1;
    f(i,1,n){
        while(s<n&&x[s+1]<=x[i]+D)s++;
        nx[i]=s;
    }
    s=1;
    f(i,1,n){
        while(x[s]<x[i]-D)s++;
        pr[i]=s;
    }
    int ls=0,cur=0;
    f(i,1,n){
        while(cur<n&&nx[cur+1]==i)++cur;
        frt[i]=max(0ll,min(cur,i-1)-max(ls+1,pr[i]+1)+1)+1;
        ls=cur;
    }
    ls=n+1,cur=n+1;
    F(i,n,1){
        while(cur>1&&pr[cur-1]==i)--cur;
        bck[i]=max(0ll,min(ls-1,nx[i]-1)-max(cur,i+1)+1)+1;
        ls=cur;
    }
    ls=n+1,cur=n+1;
    while(pr[cur-1]==n)--ls,--cur;
    F(i,n,1){
        while(cur>1&&pr[cur-1]==i-1)--cur;
        bck1[i]=max(0ll,min(ls-1,nx[i]-1)-max(cur,i+1)+1);
        ls=cur;
    }
    f(i,1,n)nx[i]==i&&(nx[i]=0),pr[i]==i&&(pr[i]=0);
    // f(i,1,n)cout<<nx[i]<<" ";cout<<endl;
    // f(i,1,n)cout<<pr[i]<<" ";cout<<endl;
    // f(i,1,n)cout<<frt[i]<<" "<<bck[i]<<" "<<bck1[i]<<endl;
    f(i,1,n)if(pr[i]&&nx[pr[i]]==i)pre[i]=pre[pr[i]]+frt[i];else pre[i]=frt[i];
    F(i,n,1)if(nx[i]&&pr[nx[i]]==i)suf[i]=suf[nx[i]]+bck[i];else suf[i]=bck[i];
    // f(i,1,n)cout<<pre[i]<<" "<<suf[i]<<endl;
    int ans=0;
    f(i,1,n)if(nx[i]&&nx[nx[i]]&&pr[nx[nx[i]]]+1==nx[i]&&pr[pr[nx[nx[i]]]]==i)ans+=pre[i]*suf[nx[nx[i]]];
    f(i,1,n)if(nx[i]&&nx[nx[i]]&&pr[nx[nx[i]]]+1==nx[i]&&pr[pr[nx[nx[i]]]]<i)ans+=suf[nx[nx[i]]];
    f(i,1,n)if(pr[i]&&pr[pr[i]]&&nx[pr[pr[i]]]-1==pr[i]&&nx[nx[pr[pr[i]]]]>i)ans+=pre[pr[pr[i]]];
    f(i,1,n)if(nx[i]&&nx[nx[i]]&&pr[nx[i]-1]<i)ans+=bck1[nx[i]];
    printf("%lld\n",ans);
}
// #define XQZ
signed main(){
#ifndef XQZ
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
#ifdef NXD
    int c=0,t=0;cin>>c>>t;while(t--)
#endif
    gs();
    cerr<<"time:"<<clock()<<"ms.\n";
    return 0;
}