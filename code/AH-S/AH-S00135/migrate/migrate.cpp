#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e4+10;
int c,t,mp[N],dp[N][N],bj[N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,cnt=0;cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>mp[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((mp[j]-mp[i])<=d&&dp[i-1][j]==0){
                    dp[i][j]=1;
                    bj[j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(bj[i]==2) cnt++;
        }
        cout<<cnt<<endl;
        for(int i=1;i<=n;i++){
            mp[i]=0;
            bj[i]=0;
            for(int j=i+1;j<=n;j++){
                dp[i][j]=0;
            }
        }
    }
    return 0;
}
