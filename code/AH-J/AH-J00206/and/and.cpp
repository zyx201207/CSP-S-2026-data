#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],maxn,ans[N],vis[N],sum[N],d[N];
bool checkA(){
    for(long long i=1;i<=n;i++){
        long long f=0;
        for(long long i=1;i<=30;i++)
            if(a[i]==pow(2,i)-1){f=1;continue;}
        if(!f) return false;
    }
    return true;
}
void dfs(long long cur){
    if(cur>m){
        long long sum=ans[1];
        for(long long i=2;i<=m;i++){
            sum&=ans[i];
        }
        maxn=max(maxn,sum);
        return ;
    }
    for(long long i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        ans[cur]=a[i];
        dfs(cur+1);
        vis[i]=0;
        ans[cur]=0;
    }
}
void try25(){
    dfs(1);
    cout<<maxn;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    if(n<=20) try25();
    else if(m==1){
        for(long long i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
    }
    else if(m==n){
        long long sum=a[1];
        for(long long i=2;i<=n;i++) sum&=a[i];
        cout<<sum;
    }
    else if(m==2&&n<=2000){
        for(long long i=1;i<=n;i++)
            for(long long j=i+1;j<=n;j++)
                maxn=max(maxn,a[i]&a[j]);
        cout<<maxn;
    }
    else if(checkA()){
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        cout<<a[m];
    }
    else{
        for(long long i=1;i<=n;i++) d[i]=a[i];
        for(long long i=1;i<=n;i++)
            d[i]=max(d[i],d[i-1]&a[i]);
        cout<<d[n];
    }
    return 0;
}
