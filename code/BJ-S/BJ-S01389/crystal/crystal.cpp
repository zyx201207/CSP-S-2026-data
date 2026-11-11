#include <bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define _rep(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=5e5+11;
int n,m,a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    bool flag1=1,flag2=1;
    rep(i,1,n){
        scanf("%lld",a+i);
        if(a[i]!=i)flag1=0;
    }
    sort(a+1,a+n+1);
    rep(i,2,n-1)
        if((a[i]-a[i-1])!=(a[i+1]-a[i]))flag2=0;
    if(flag1){
        int sum=0;
        rep(i,1,n-1){
            sum+=i;
            if(sum>n){
                printf("%lld\n",i+1);
                return 0;
            }
        }
    }
    if(flag2){
        int max1=1e18,max2=1e18;
        rep(i,1,n){
            if(a[i]<max1){
                max2=max1;
                max1=a[i];
            }
            else if(a[i]<max2)
                max2=a[i];
        }
        int sum=0,t=max2-max1;
        rep(i,1,n-1){
            sum+=i*t;
            if(sum>n){
                printf("%lld\n",i+1);
                return 0;
            }
        }
    }
    _rep(len,n,2){
        rep(i,1,n-len+1){
            int j=i+len-1,sum=0;
            rep(k,i,j)
                sum+=(abs(a[k]-a[j]));
            if(sum<=m){
                printf("%lld\n",len);
                return 0;
            }
        }
    }
    return 0;
}
