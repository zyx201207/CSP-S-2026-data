#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    long long w[m+5];
    long long dp[n+5][m+5];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        long long k;
        cin>>k;
        while(k--){
            long long a,b;
            cin>>a>>b;
            dp[i][a]=b;
        }
    }
    vector<int> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]!=0 && dp[i+1][j]!=0){
                q.push_back(j);
            }
        }
    }
    long long ans=0;
    while(p--){
        int a,b;
        cin>>a>>b;
        ans=0;
        ans=ans+w[a]+w[b];
        for(int i=1;i<=n;i++){
            if(dp[i][a]!=0&&dp[i][b]!=0){
                ans=ans+dp[i][a]+dp[i][b];
                cout<<ans<<'\n';
                break;
            }else {
                int u=q.front();
                q.pop_back();
                ans=ans+dp[i][a]+dp[i][u]+dp[i+1][u]+dp[i+1][b];
                cout<<ans<<'\n';
                break;
            }
            break;
        }
    }
    return 0;
}
