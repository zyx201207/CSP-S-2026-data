#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2000005;
int T,n;
LL d,a[N],ans,k;
bool flag;
pair<int,int> dp[5005][5005],dpa[N];
int main(){
    ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>T>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        k=a[2]-a[1];
        flag=1;
        for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=k) flag=0;
        if(flag){
            for(int i=1;i<=n;i++) dpa[i]={0x3f3f3f3f,0};
            dpa[1]={1,1};
            for(int i=2;i<=n;i++){
                for(int j=i-1;j>=1;j--){
                    if(a[i]-a[j]>d) break;
                    if(dpa[j].first+1<dpa[i].first) dpa[i]={dpa[j].first+1,dpa[j].second};
                    else if(dpa[j].first+1==dpa[i].first) dpa[i].second+=dpa[j].second;
                }
            }
            for(int i=2;i<=n;i++){
                if(dpa[i].second==2) ans+=n-i+1;
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]={0x3f3f3f3f,0};
        for(int i=1;i<n;i++){
            dp[i][i]={1,1};
            for(int j=i+1;j<=n;j++){
                for(int k=j-1;k>=i;k--){
                    if(a[j]-a[k]>d) break;
                    if(dp[i][k].first+1<dp[i][j].first) dp[i][j]={dp[i][k].first+1,dp[i][k].second};
                    else if(dp[i][k].first+1==dp[i][j].first) dp[i][j].second+=dp[i][k].second;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(dp[i][j].second==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
