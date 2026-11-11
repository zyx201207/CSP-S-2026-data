#include<bits/stdc++.h>
using namespace std;
using lld=long long;
void solve1(){
    lld n,d;
    cin>>n>>d;
    vector<lld> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++){
            int len=(r-l-1);
            int minn=INT_MAX,minsum=0;
            for(int mask=0;mask<=(1<<len)-1;mask++){
                bool ok=1;
                int lst=l,cnt=0;
                for(int i=1;i<=len;i++){
                    if((mask>>(i-1))&1){
                        cnt++;
                        //cout<<l<<' '<<r<<' '<<lst<<' '<<l+i<<' '<<a[l+i]-a[lst]<<'\n';
                        if(a[l+i]-a[lst]>d){ok=0;break;}
                        lst=l+i;
                    }
                }
                if(ok&&a[r]-a[lst]<=d){
                    if(cnt==minn){
                        minsum++;
                    }
                    if(cnt<minn){
                        minsum=1;
                        minn=cnt;
                    }
                }
            }
            //cout<<minsum<<'\n';
            if(minsum==2){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
    return;
}
const int N=3005;
int dp[N][N],cnt[N][N];
void solve2(){
    lld n,d;
    cin>>n>>d;
    vector<lld> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=0x3f3f3f3f;
            cnt[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]-a[i]<=d) dp[i][j]=1,dp[j][i]=1,cnt[i][j]=1,cnt[j][i]=1;
            else break;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]!=0x3f3f3f3f&&dp[k][j]!=0x3f3f3f3f){
                    if(dp[i][k]+dp[k][j]<dp[i][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                        cnt[i][j]=cnt[i][k]*cnt[k][j];
                    }
                    else if(dp[i][j]==dp[k][j]+dp[i][k]){
                        cnt[i][j]+=cnt[k][j]*cnt[i][k];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(cnt[i][j]==2) ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        if(c==0||c==1||c==2) solve1();
        else solve2();
    }
    return 0;
}