#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long x[2000001],dp[2000001],cnt[2000001],sum[2000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n;
        cin>>d;
        for(int i=1;i<=n;i++){
            dp[i]=cnt[i]=0;
            cin>>x[i];
        }

            int ans=0;
            for(int i=1;i<n;i++){
                int l=i;
                dp[i]=0;
                sum[0]=1;
                int cnt1=0;
                int cnt2=0;
                for(int j=i+1;j<=n;j++){
                    sum[j-i]=0;
                    dp[j]=0x3f3f3f3f;
                    while(x[j]-x[l]>d){
                        if(cnt[l]==1)cnt1--;
                        if(cnt[l]==2)cnt2--;
                        sum[dp[l]]-=cnt[l],l++;
                    }
                    if(l==j)break;
                    dp[j]=min(dp[j],dp[l]+1);
                    cnt[j]=sum[dp[l]];
                    if(cnt[j]==1)cnt1++;
                    if(cnt[j]==2){
                            cnt2++;
                        ans++;
                    }
                    if(cnt1==0&&cnt2==0)break;
                    sum[dp[j]]+=cnt[j];
                }
            }
            cout<<ans<<'\n';
    }
    return 0;
}
