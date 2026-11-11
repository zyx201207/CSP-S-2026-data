#include<bits/stdc++.h>
using namespace std;
long long n,m;
map<long long,long long>ma;
long long maxn=0;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long _;
    scanf("%lld %lld",&_,&m);
    for(long long i=1;i<=_;i++){
        long long p;
        scanf("%lld",&p);
        p=p+100000000001;
        ma[p]++;
        if(ma[p]==1){
            a[++n]=p;
        }
    }
    sort(a+1,a+n+1);
    long long l=0,r=0;
    long long xh=0;
    long long cnt=0;
    long long ok=0;//有无残留；
    long long cls=0;//残留数；
    while(r<n){
        r++;
        xh+=(a[r]-a[r-1])*cnt;
        cnt+=ma[a[r]];
        if(ok){
            long long xhs=min((xh-m+a[r]-a[l-1]+1)/(a[r]-a[l-1]),cls);
            xh-=xhs*(a[r]-a[l-1]);
            cls-=xhs;
            cnt-=xhs;
            if(cls==0){
                ok=0;
            }
        }
        while(xh>m){
            xh-=(a[r]-a[l])*ma[a[l]];
            cnt-=ma[a[l]];
            l++;
        }
        if(l-1!=r&&l-1>0){
          if((m-xh)/(a[r]-a[l-1])!=0){
            cls=(m-xh)/(a[r]-a[l-1]);
            cnt+=cls;
            ok=1;
            xh+=cls*(a[r]-a[l-1]);
          }
        }
        maxn=max(maxn,cnt);
    }
    printf("%lld",maxn);
    return 0;
}
