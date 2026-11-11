#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1,greater<long long>());
    long long ans=a[m];
    for(long long i=1;i<m;i++) ans&=a[i];
    printf("%lld",ans);
    return 0;
}
