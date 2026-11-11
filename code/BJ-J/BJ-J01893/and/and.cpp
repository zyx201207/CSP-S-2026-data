#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+13;
int maxn,n,m,ans1,ans2,ans3,a[N],dp[2013][2013];//dp[i][j]:max sum when we select i numbers from the 1st j numbers
bool fl;
void dfs(int pre,int dep,int sum){
    if(dep==m){maxn=max(maxn,sum);return;}
    for(int i=pre+1;i<=n;i++){
        dfs(i,dep+1,(sum&a[i]));
    }
}
bool f(int x){
    bool t=1;
    while(x){
        t&=(x%2);
        x/=2;
    }
    return t;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    fl=1;
    ans3=1e9+13;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans1=max(ans1,a[i]);
        if(i==1)ans2=a[i];
        else ans2&=a[i];
        if(!f(a[i]))fl=0;
    }
    if(m==n)return cout<<ans2<<'\n',0;
    if(m==1)return cout<<ans1<<'\n',0;
    if(fl){
        sort(a+1,a+1+n);
        cout<<a[n-m+1]<<'\n';
        return 0;
    }
    if(m<=5){
        dfs(0,0,(1<<30)-1);
        cout<<maxn<<'\n';
        return 0;
    }
    if(m<=20){
        for(int i=1;i<=n;i++)dp[1][i]=a[i];
        for(int i=2;i<=m;i++){
            for(int j=i;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                for(int k=i-1;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]&a[j]);
                }
            }
        }
        cout<<dp[m][n]<<'\n';
        return 0;
    }
    return 0;
}

