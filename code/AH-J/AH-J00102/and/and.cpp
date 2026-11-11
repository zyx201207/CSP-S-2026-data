#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,m,a[N],maxn;
void dfs(LL cur,LL sum,LL cnt){
    if(cnt==m){
        maxn=max(maxn,sum);
        return ;
    }
    if(cnt+n-cur+1<m) return ;
    if(cnt==0){
        dfs(cur+1,a[cur],cnt+1);
        dfs(cur+1,0,cnt);
    }
    else{
        dfs(cur+1,sum&a[cur],cnt+1);
        dfs(cur+1,sum,cnt);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(m==1){
        for(LL i=1;i<=n;i++) maxn=max(maxn,a[i]);
    }
    else if(m==2){
        for(LL i=1;i<n;i++){
            for(LL j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    else if(m==n){
        LL sum=a[1];
        for(LL i=1;i<=n;i++) sum&=a[i];
        maxn=sum;
    }
    else if(n<=20){
        dfs(1,0,0);
    }
    else{
        sort(a+1,a+n+1);
        maxn=a[n-m+1];
    }
    printf("%lld",maxn);
    return 0;
}
