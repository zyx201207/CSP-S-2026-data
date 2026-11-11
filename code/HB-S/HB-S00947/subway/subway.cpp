#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005];
vector<pair<long long,long long>> stn[500005];
map<pair<int,long long>,long long> ttime; 
long long dp[505][505];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        for(int j=1;j<=x;j++){
            long long ai,ti;
            cin>>ai>>ti;
            stn[ai].push_back({i,ti});
            ttime[{i,ai}]=ti;
        }
    }
    for(int i=0;i<505;i++) for(int j=0;j<505;j++) if(i!=j) dp[i][j]=9e12;
    for(int i=1;i<m;i++){
        for(int j=0;j<(int)stn[i].size()-1;j++){
            for(int k=j+1;k<(int)stn[i].size();k++){
                long long stn1=stn[i][j].first,t1=stn[i][j].second,stn2=stn[i][k].first,t2=stn[i][k].second;
                dp[stn1][stn2]=min(dp[stn1][stn2],t1+t2);
                dp[stn2][stn1]=min(dp[stn2][stn1],t1+t2);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<(int)path[i].size();j++){
    //         cout<<endl<<i<<' '<<path[i-1][j].second<<" "<<path[i][j].first<<endl;
    //     }
    //     cout<<endl;
    // }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        long long ans=9e12;
        for(int j=0;j<(int)stn[x].size();j++){
            for(int k=0;k<(int)stn[y].size();k++){
                int stn1=stn[x][j].first,stn2=stn[y][k].first;
                ans=min(ans,w[x]+w[y]+dp[stn1][stn2]+ttime[{stn1,x}]+ttime[{stn2,y}]);
            }
        }
        cout<<ans<<'\n';
    }
}
/*
Floyd
consider each subway line as a node each zhongzhuanzhan as an edge
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/