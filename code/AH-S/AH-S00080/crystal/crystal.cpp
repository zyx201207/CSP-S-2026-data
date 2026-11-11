#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b,s[500005],d=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=2;i<=n+1;i++){
        if(a[i]>a[i-1]){
            b=a[i-1];
            a[i-1]=a[i];
            a[i]=b;
            if(i<=2) i--;
             else i-=2;
        }
    }
    for(long long i=1;i<=n;i++){
        long long k=m;
        for(long long j=i+1;j<=n;j++){
            if(a[j]+k>=a[i]&&a[j]<=a[i]){
                k+=a[j];
                k-=a[i];
                s[i]++;
            }
        }
    }
    for(long long i=1;i<=n;i++){
        if(s[i]>d) d=s[i];
    }
    printf("%lld",d+1);
    return 0;
}
