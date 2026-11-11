#include<bits/stdc++.h>
using namespace std;

struct n1{
    int li,t;
};
long long c,n,m,d,q,w[500005],ans,s,e;
vector<n1> mp1[500005];
long long dp[505][505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=LLONG_MAX;
            if(i==j){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(t--){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            mp1[tmp1].push_back({i,tmp2});
        }
    }
    for(int i=1;i<=m;i++){
        if(mp1[i].size()!=1){
            for(int j=0;j<mp1[i].size()-1;j++){
                for(int k=j+1;k<mp1[i].size();k++){
                    dp[min(mp1[i][j].li,mp1[i][k].li)][max(mp1[i][j].li,mp1[i][k].li)]=
                    min(
                        1ll*(mp1[i][j].t+mp1[i][k].t),
                        dp[min(mp1[i][j].li,mp1[i][k].li)][max(mp1[i][j].li,mp1[i][k].li)]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                if(dp[min(i,j)][max(i,j)]!=LLONG_MAX&&dp[min(i,k)][max(i,k)]!=LLONG_MAX)
                dp[j][k]=min(dp[min(i,j)][max(i,j)]+dp[min(i,k)][max(i,k)],dp[j][k]);
            }
        }
    }
    while(q--){
        cin>>s>>e;
        ans=LLONG_MAX;
        for(auto i:mp1[s]){
            for(auto j:mp1[e]){
                ans=min(ans,dp[min(i.li,j.li)][max(i.li,j.li)]+i.t+j.t);
            }
        }
        cout<<ans+w[s]+w[e]<<'\n';
    }
    return 0;

}
