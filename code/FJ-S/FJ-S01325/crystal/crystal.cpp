#include<bits/stdc++.h>
const int N=5e5;
int n,ans;
long long m,a[N+5];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    std::sort(a+1,a+n+1);
    long long s=0;
    for(int i=1,j=1;i<=n;++i){
        while(s>m){
            s-=(a[i]-a[j]);
            ++j;
        }
        ans=std::max(ans,i-j+1);
        if(i!=n)s+=(a[i+1]-a[i])*(i-j+1);
    }
    printf("%d",ans);
    return 0;
}