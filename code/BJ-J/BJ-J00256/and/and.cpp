#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5+10;
long long a[maxn];
long long dp[10001][1001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin >> n >> m;
    for(int i =0;i < n;i++){
        cin >> a[i];
        if(i==0) dp[1][i]=a[i];
        else dp[1][i]=max(dp[i-1][1],a[i]);
    }
    for(long long i = 2;i <= m;i++){
        for(long long j = 0;j < n;j++){
            if(i > j+1) dp[i][j]=INT_MIN;
            dp[i][j]=max(dp[i-1][j-1] & a[j],dp[i][j-1]);
        }
    }
    long long ans=0;
    for(int i = 0;i < n;i++){
        ans=max(ans,dp[m][i]);
    }
    cout << ans;
    return 0;
}
