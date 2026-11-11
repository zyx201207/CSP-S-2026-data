#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505,maxm=5e5+5;
vector<pair<int,int> > v[maxm];
int dp[maxn][maxn],c,n,m,d,q,w[maxm];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,t;
            cin>>x>>t;
            pair<int,int> pp;
            pp.first=i;
            pp.second=t;
            v[x].push_back(pp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1e18;
            if(i==j){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                dp[v[i][j].first][v[i][k].first]=min(dp[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
                dp[v[i][k].first][v[i][j].first]=min(dp[v[i][k].first][v[i][j].first],v[i][j].second+v[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=1e18;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                int line1=v[x][i].first,line2=v[y][j].first;
                ans=min(ans,dp[line1][line2]+v[x][i].second+v[y][j].second);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
