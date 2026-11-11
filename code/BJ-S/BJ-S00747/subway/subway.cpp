#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
ll w[1145140];
struct node{
    ll v,w;
};
vector<node> G[505];
vector<node> sta[500005];
ll dp[505][505];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            node t;
            cin>>t.v>>t.w;
            //v: current station idx
            //w: time of go to the lobby
            //j.v: subway idx
            for(node j:sta[t.v]){
                G[j.v].push_back({i,t.w+j.w});
                G[i].push_back({j.v,t.w+j.w});
            }
            sta[t.v].push_back({i,t.w});
        }
    }
    memset(dp,0x3f,sizeof(dp));
    /*for(int i=1;i<=n;i++){
        for(node j:G[i])
            cout<<'('<<j.v<<','<<j.w<<") , ";
        cout<<'\n';
    }*/

    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        for(node j:G[i])
            dp[i][j.v]=min(dp[i][j.v],j.w);
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cout<<dp[i][j]<<' ';
        cout<<'\n';
    }*/

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=
                    min(dp[i][j],dp[i][k]+dp[k][j]);
    while(q--){
        int st,ed;
        cin>>st>>ed;
        ll ans=1e18;
        for(node i:sta[st])
            for(node j:sta[ed])
                ans=min(ans,dp[i.v][j.v]+i.w+j.w);
        cout<<ans+w[st]+w[ed]<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
