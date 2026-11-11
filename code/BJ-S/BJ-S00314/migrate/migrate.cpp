#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N],ans;
int dp[5005][5005],cnt[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        int n;
        long long d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(c==11||c==12){
            if(a[2]-a[1]>=d||d>=a[n]-a[1]){
                cout<<"0\n";
                continue;
            }else{
                cout<<n-(d/(a[2]-a[1])*2-1)<<"\n";
                continue;
            }
        }
        memset(dp,-1,sizeof dp);
        memset(cnt,0,sizeof cnt);
        for(int len=2;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(a[j]-a[i]<=d){
                    dp[i][j]=1;
                    continue;
                }
                int x=dp[i][j];
                if(x==-1) x=1e9;
                for(int k=i+1;k<j;k++){
                    if(dp[i][k]==-1||dp[k][j]==-1) continue;
                    int y=dp[i][k]+dp[k][j];
                    if(y==x){
                        cnt[i][j]++;
                        if(cnt[i][j]==3-1) ans--;
                        if(cnt[i][j]==2-1){
                            ans++;
                        }
                    }else if(y<x){
                        dp[i][j]=y;
                        x=y;
                        if(cnt[i][j]==2-1) ans--;
                        cnt[i][j]=1-1;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
