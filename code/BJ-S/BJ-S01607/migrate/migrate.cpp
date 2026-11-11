#include<bits/stdc++.h>
#define ll long long
#define N 315
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll dp[N][N],s[N][N];
ll a[N*N];
ll n,d,c,T;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    qck;
    cin>>c>>T;
    while(T--){
        memset(dp,0x3f,sizeof(dp));
        memset(s,0,sizeof(s));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]>d) break;
                dp[j][i]=1;
                s[j][i]=1;
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(i==j) continue;
                    if(dp[i][k]+dp[k][j]==dp[i][j]){
                        s[i][j]+=s[i][k]*s[k][j];
                        if(s[i][j]>2) s[i][j]=-1;
                        // cout<<k<<" "<<i<<" "<<j<<"\n";
                    }else if(dp[i][k]+dp[k][j]<dp[i][j]){
                        dp[i][j]=dp[i][k]+dp[k][j],s[i][j]=s[i][k]*s[k][j];
                        if(s[i][j]>2) s[i][j]=-1;
                        // cout<<k<<"_"<<i<<"_"<<j<<"\n";
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            // for(int j=1;j<=i;j++) cout<<"0 ";
            for(int j=i+1;j<=n;j++){
                // cout<<dp[i][j]<<" ";
                if(s[i][j]==2) ans++;
            }
            // cout<<"\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}