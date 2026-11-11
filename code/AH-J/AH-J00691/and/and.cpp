#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL a[N],maxn;
LL n,m;
void f(LL cur,LL ans,LL pre){
    if(cur==m){
        maxn=max(maxn,ans);
        return ;
    }
    for(LL i=pre+1;i<=n;i++){
        f(cur+1,ans&a[i],i);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxn=max(maxn,a[i]);
    }
    if(m==n){
        LL ans=a[1];
        for(LL i=2;i<=n;i++) ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    maxn=0;
    if(m==2){
        for(LL i=1;i<=n;i++){
            for(LL j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(n<=25){
        for(LL i=1;i<=n;i++){
            f(1,a[i],i);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n-1){
        LL sum=2,T=30;
        while(T--) sum*=2;
        sum++;
        LL tmp=sum;
        for(LL i=1;i<=n;i++){
            tmp=sum;
            for(LL j=1;j<=n;j++){
                if(i!=j) tmp&=a[j];
            }
            maxn=max(maxn,tmp);
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+n+1);
    LL sum=a[n];
    for(LL i=n-1;i>n-m;i--) sum&=a[i];
    cout<<sum;
    return 0;
}
