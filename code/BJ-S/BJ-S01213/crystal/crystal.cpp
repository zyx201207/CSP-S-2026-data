#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
long long b[500005];
bool check(long long x){
    //printf("%lld\n",x);
    for(long long zh=x;zh<=n;zh++){
        long long sum=0;
        for(long long i=zh-x+1;i<zh;i++){
            sum=sum+(a[i+1]-a[i])*(i-zh+x);
        }
        if(sum<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);

    int st1=1,st2=1;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++){
        if(a[i]!=i){
            st1=0;
            break;
        }
    }
    for(long long i=2;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]){
            st2=0;
            break;
        }
    }

    if(st1==1){
        long long cnt=1;
        if(m<1){
            printf("1");
            return 0;
        }
        while(m>=cnt){
            m=m-cnt;
            cnt++;
        }
        printf("%lld",cnt);
        return 0;
    }
    if(st2==1){
        long long x=a[2]-a[1];
        long long now=1;
        if(m<x*now){
            printf("1");
            return 0;
        }
        while(m>=x*now){
            m=m-x*now;
            now++;
        }
        printf("%lld",now);
        return 0;
    }
    //printf("!!!!!!!!!!!!!");
    sort(a+1,a+n+1);
    long long l=0,r=n;
    long long ans=1;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%lld",ans);
    return 0;
}
