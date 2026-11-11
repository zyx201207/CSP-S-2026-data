#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[310][310][310]={};

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        memset(dp,0,sizeof(dp));
        int x[310]={};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            dp[i][i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;x[j]-x[k]<=d&&k>=i;k--){
                    for(int l=1;l<=300;l++){
                        dp[i][j][l]+=dp[i][k][l-1];
                    }
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int k;
                for(k=1;dp[i][j][k]==0&&k<300;k++);
                if(dp[i][j][k]==2){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }//1-2 8pts
    return 0;
}
