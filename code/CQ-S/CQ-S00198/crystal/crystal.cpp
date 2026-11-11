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
const int N=5e5+10;
int n,m,a[N];
void gs(){
    n=read(),m=read();
    f(i,1,n)a[i]=read();
    sort(a+1,a+1+n);
    priority_queue<pri_grt(int)>q;
    int s=0,ans=0;
    f(i,1,n){
        q.push(a[i]),s+=a[i];
        while(!q.empty()&&q.size()*a[i]-s>m)s-=q.top(),q.pop();
        updmax(ans,(int)q.size());
    }
    printf("%lld\n",ans);
}
// #define XQZ
signed main(){
#ifndef XQZ
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
#ifdef NXD
    int t=0;cin>>t;while(t--)
#endif
    gs();
    return 0;
}