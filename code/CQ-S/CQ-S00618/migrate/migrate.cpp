#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 2e6+5;
int c,n,d,a[M],ans;
int nx[M],sum[M];
vector<int>ve[M];
int dp[M][2];
void Main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n,j=n;i>0;i--){
        while(a[j]-a[i]>d)j--;
        nx[i]=j;
        ve[j].push_back(i);
    }
    dp[1][0]=1;
    //u->i->v <-> u->i-1->v
    int tp=0;
    for(int i=2;i<=n;i++){
        if(nx[i]==i){
            for(int u:ve[i])if(u!=i){
                dp[i][0]+=dp[u][0],dp[i][1]+=dp[u][1];
            }
            ans+=dp[i][1];
            continue;
        }
        bool fl=0;
        int k=0;
        if(nx[i-1]==nx[i]){
            if(nx[i-2]==nx[i]){
                dp[nx[i]][1]-=dp[i][1];
            }else{
                //u!=i-1
                dp[nx[i]][1]-=dp[i][1];
                for(int u:ve[i])if(u!=i){
                    int s=dp[u][0];
                    if(nx[u-1]==i-1)s=1;
                    if(nx[i]-1>nx[i-2])ans+=s*(nx[i]-1-max(nx[i-2],i));
                    dp[nx[i]][1]+=s,k+=s;
                    // ans-=s;
                    // dp[i][1]+=s;
                }
            }
        }else{
            for(int u:ve[i]){
                dp[i][0]+=dp[u][0],dp[i][1]+=dp[u][1];
                if(u!=i-1){
                    int s=dp[u][0];
                    if(nx[u-1]==i-1)s=1;
                    int mx=nx[i-1],mn=max(i+1,nx[i-2]+1);
                    if(mx>=mn){
                        ans+=s*(mx-mn+1);
                    }
                }
            }
        }
        dp[i][0]++;
        if(nx[i]!=nx[i-1]){
            if(nx[i]-1-max(nx[i-1],i)>0){
                ans+=(dp[i][1]+k)*(nx[i]-1-max(nx[i-1],i));
            }
        }
        ans+=dp[i][1];
    }
    cout<<ans<<"\n";
    ans=0;
    for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=nx[i]=0,ve[i].clear();
}
signed main(){
    // freopen("1.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // freopen("1.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T=1;
    cin>>c>>T;
    while(T--)Main();
}