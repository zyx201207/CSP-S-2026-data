#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll a[200010],maxn=-1;
ll dp[200010];
bool cmp(const ll &x,const ll &y){
    return x>y;
}
void dfs(ll cur,ll now,ll last){
    if(last+(m-cur+1)>n)    return;
    if(now<=maxn)    return;
    if(cur>m){
        maxn=max(maxn,now);
        return;
    }
    for(int i=last+1;i<=n;i++){
        dfs(cur+1,now&a[i],i);
    }
}
void solve(){
    if(m==1)    maxn=a[1];
    else if(m==n){
        for(int i=1;i<=n;i++)   a[1]=a[1]&a[i];
        maxn=a[1];
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int f=1;
    for(int i=1;i<=n;i++){
        int t=a[i]+1;
        while(t%2==0)   t/=2;
        if(t!=1){
            f=0;
            break;
        }
    }
    if(f==1){
        maxn=a[n-m+1];
    }
    else if(n<=20){
        dfs(1,pow(2,30)-1,0);
    }
    else if(n<=2000){
        solve();
    }
    else{
        for(int i=1;i<=n;i++)   dp[i]=a[1];
        for(int i=2;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(j>i) dp[j]=dp[i]&a[i];
                else    dp[j]=max(dp[j],dp[j-1]&a[i]);
            }
        }
        maxn=dp[m];
    }
    cout<<maxn<<endl;
    return 0;
}
