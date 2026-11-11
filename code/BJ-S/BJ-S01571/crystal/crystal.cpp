/*
f[l][r]=f[l+1][r]+(a[r]-a[l])

*/


#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n;
ll a[5000005];
int ans=1;
ull cost,m;

#define DEBUG true

#define D(x) if(dbg&(1<<x))
ull dbg=(
(1<<0)|
(1<<1)| // ccost dump
(1<<2)| // print neighbour at break
(1<<3)|
(1<<4)|
(1<<5)|
// ENABLE/DISABLE DEBUG
0)
;
#if DEBUG
char buf[65535];
#else
char buf[256];
#endif
// #define DPR(x) { char t[256]; sprintf(t,x); cout << t; }

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    char *bp=buf;
// ====================================
    scanf("%d%llu",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",a+i);
    if(n==1){
        printf("1\n"); goto end;
    }
    sort(a+1,a+n+1);
    if(m==0){ // CHOOSE LONGEST CONT
        ull cont=1,ans=1;
        for(int i=2;i<=n;++i){
            if(a[i]==a[i-1])++cont;
            else{
                ans=max(cont,ans);
                cont=1;
            }
        }
        printf("%llu\n",ans);
        goto end;
    }
    for(int lp=n,rp=n;lp>=1;--lp){
        cost+=a[rp]-a[lp];
        if(cost<=m){
            ans=max(ans,rp-lp+1);
        }
        while(cost>m && lp<rp){
            while( lp<rp && a[rp-1]==a[rp]) --rp;
            if(lp<rp){ cost-= (rp-lp)*(a[rp]-a[rp-1]); --rp; }
        }
        if(cost<=m){
            ans=max(ans,rp-lp+1);
        }
    }
    printf("%d\n",ans);
end:
    if(DEBUG)cout<<buf;
    return 0;
}