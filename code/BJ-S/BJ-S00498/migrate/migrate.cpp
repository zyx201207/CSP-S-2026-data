#include<bits/stdc++.h>
using namespace std;
long long n,x[10005],d,c,t,dp[1005][1005],sum;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=1;
        dp[i][i+1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int z=1;z<=d;z++){
                dp[i][j]+=dp[i][j-z];
            }
            if(dp[i][j]==2){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
