#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long sum,mx[200005],ans;
long long dp[200005];
void dfs(int t,long long cnt,long long sum){
    if(cnt==m){
        ans=max(ans,sum);
        return ;
    }
    if(t>n) return ;
    dfs(t+1,cnt,sum);
    dfs(t+1,cnt+1,sum&a[t]);
    return ;
}
bool cmp(long long a,long long b){
    return a>b;
}
long long shu=2e30-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1) sum=a[i];
        else sum&=a[i];
        mx[i]=max(mx[i-1],a[i]);
        if((shu&a[i])!=a[i]) f=0;
    }
    if(m==n){
        cout<<sum;
        return 0;
    }else if(m==1){
        cout<<mx[n];
        return 0;
    }else if(f==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }
    else if(n<=20||m==2){
        dfs(1,0,shu);
        cout<<ans;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(i==1&&j==1) dp[j]=a[i];
            else if(j==1) dp[i]=mx[i];
            else if(j==0) dp[j]=0;
            else if(dp[j-1]!=-1&&dp[j]==-1) dp[j]=(dp[j-1]&a[i]);
            else if(dp[j-1]!=-1) dp[j]=max(dp[j],(dp[j-1]&a[i]));
        }
    }
    cout<<dp[m];
    return 0;
}
