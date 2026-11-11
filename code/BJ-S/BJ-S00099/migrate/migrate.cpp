#include<bits/stdc++.h>
using namespace std;
long long dp[5010][5010];
long long cnt[5010][5010];
long long x[5010];
const long long oo=1e18;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _,T;
    cin>>_>>T;
    while(T--){
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
            cnt[i][i]=1;
        }
        for(int len=1;len<n;len++){
            for(int i=1;i+len<=n;i++){
                int j=len+i;
                dp[i][j]=oo;
                cnt[i][j]=0;
                if(abs(x[i]-x[j])<=d){
                    dp[i][j]=1;
                    cnt[i][j]=1;
                    continue;
                }
                for(int k=i+1;k<j;k++){
                    long long cst=dp[i][k]+dp[k][j];
                    if(cst==dp[i][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
                    else if(cst<dp[i][j])cnt[i][j]=cnt[i][k]*cnt[k][j],dp[i][j]=cst;
                }
                cnt[i][j]/=dp[i][j]-1;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++){
                if(cnt[i][j]==2)ans++;
            }
        cout<<ans<<endl;
    }
    return 0;
}