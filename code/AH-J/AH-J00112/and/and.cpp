#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],b=0,s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            long long c=a[i-1];
            a[i-1]=a[i];
            a[i]=c;
            i--;
        }
    }
    for(long long i=2;i<=n;i++){
        if(a[i]>a[i-1]){
            long long c=a[i-1];
            a[i-1]=a[i];
            a[i]=c;
            i--;
        }
    }
    b=a[1];
    m--;
    for(long long i=2;i<=n;i++){
        if(m>=1){
            b&=a[i];
            m--;
        }
         else break;
    }
    printf("%lld",b);
    return 0;
}
