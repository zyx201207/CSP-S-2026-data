#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MIN,a[200000+5],x[200000+5];
void sol_dfs(long long cur,long long k){
    if(cur>m){
        for(long long i=1;i<=m;i++) x[1]&=x[i];
        if(x[1]>ans) ans=x[1];
        return;
    }
    for(long long i=k;i<=n;i++){
        x[cur]=a[i];
        sol_dfs(cur+1,i+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(m==n){
        for(long long i=1;i<=n;i++) a[1]&=a[i];
        ans=a[1];
    }
    else{
        sort(a+1,a+n+1);
        sol_dfs(1,1);
    }
    printf("%lld",ans);
    return 0;
}