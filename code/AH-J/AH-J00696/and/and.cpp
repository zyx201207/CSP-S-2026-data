#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n,m,a[N],ans,l[N],r[N];
void dfs(LL cur,LL x,LL cnt){
    if(cnt>=m||cur>n){
        if(cnt>=m) ans=max(ans,x);
        return;
    }
    dfs(cur+1,x,cnt);
    if(x!=0) dfs(cur+1,x&a[cur],cnt+1);
    else dfs(cur+1,a[cur],cnt+1);
}
void try1(){
    dfs(1,0,0);
    cout<<ans;
}
void try2(){
    LL maxn=-1;
    for(LL i=1;i<=n;i++) maxn=max(maxn,a[i]);
    cout<<maxn;
}
void try3(){
    LL maxn=-1;
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=n;j++){
            if(i!=j) maxn=max(maxn,a[i]&a[j]);
        }
    }
    cout<<maxn;
}
void try4(){
    LL sum=a[1];
    for(LL i=2;i<=n;i++) sum=sum&a[i];
    cout<<sum;
}
void try5(){
    l[1]=a[1];
    for(LL i=2;i<=n;i++) l[i]=a[i]&l[i-1];
    r[n]=a[n];
    for(LL i=n-1;i>=1;i--) r[i]=a[i]&r[i+1];
    LL maxn=max(r[2],l[n-1]);
    for(LL i=2;i<n;i++) maxn=max(maxn,l[i-1]&r[i+1]);
    cout<<maxn;

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    LL ok=1;
    for(LL i=1;i<=n;i++){
       scanf("%lld",&a[i]);
       if(a[i]!=(1<<i)-1) ok=0;
    }
    if(ok) cout<<a[n-m+1];
    else if(n<=20&&m<=20) try1();
    else if(n<=2000&&(m==1||m==2||m==n)){
        if(m==1) try2();
        else if(m==2) try3();
        else if(m==n) try4();
    }else if(m==n-1) try5();
    return 0;
}
