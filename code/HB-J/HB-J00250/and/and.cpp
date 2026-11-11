#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],dp[2005][20005],maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    dp[1][0]=1111111111;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[1][i]=a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=m;i++){
        for(long long j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j-1]&a[j];
            if(i==m){
                maxn=max(maxn,dp[i][j]);
            }
        }
    }
    cout<<maxn<<"\n";
    return 0;
}
