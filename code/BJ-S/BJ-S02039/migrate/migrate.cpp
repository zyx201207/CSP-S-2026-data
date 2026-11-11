#include <bits/stdc++.h>
using namespace std;
long long x[2000005];long long dp[5005][5005];
int ans[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    for(int i=1;i<=t;i++){
        //cout<<"12"<<endl;
        int n;long long d;cin>>n>>d;int an=0;
        memset(dp,0x3f,sizeof(dp));
        memset(ans,0,sizeof(ans));
        for(int j=1;j<=n;j++){
            cin>>x[j];
            //cout<<x[j]<<' ';
        }
        queue<int> q;
        q.push(1);
        for(int e=1;e<=n-1;e++){
            for(int j=e+1;j<=n;j++){
                if((x[j]-x[e])<=d){
                    //cout<<"!";
                    dp[e][j]=1;
                    for(int k=1;k<e;k++){
                        //cout<<"! "<<k<<' '<<e<<' '<<j<<' '<<dp[k][j]<<' '<<dp[k][e]+1<<endl;
                        if (dp[k][j]==dp[k][e]+1){
                            if(ans[k][j]==0){
                                an++;
                                ans[k][j]=1;
                            }else{
                                an--;
                                ans[k][j]=2;
                            }
                        }else{

                            if (dp[k][e]+1<dp[k][j]){
                                if(ans[k][e]==1){
                                    ans[k][j]=1;an++;
                                }
                            }
                            dp[k][j]=min(dp[k][e]+1,dp[k][j]);
                        }
                    }
                }else{
                    break;
                }
            }
        }
        cout<<an<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
