#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,m,a[maxn],dp[maxn][maxn],pre[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    pre[1]=a[1];
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]&a[i];
    }
    if(m==n){
        cout<<pre[n];
        return 0;
    }
    int maxx=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>maxx){
            maxx=a[i];
        }
        dp[i][1]=maxx;
    }
    dp[1][1]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
        }
    }
    cout<<dp[n][m];
    return 0;
}
