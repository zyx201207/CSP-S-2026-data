#include<bits/stdc++.h>
#define int ll
#define all(op) op.begin(),op.end()
#define all1(op) op.begin()+1,op.end()
using namespace std;
using ll=long long;
using db=double;
using ldb=long double;
using i128=__int128_t;
const int inf=1e9+7;
const ll INF=1e18+7,M=1e12+7;
const db eps=1e-9;
void solve(){
    int n,d;cin>>n>>d;
    vector<int> a(n+1); 
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<vector<int>> e(n+1);
    int lst=1;
    for(int i=1;i<=n;i++){
        while(lst<=n&&a[i]+d>=a[lst])lst++;
        if(i==lst-1)continue;
        e[lst-1].push_back(i);
    }

//    for(int i=1;i<=n;i++){
//        cerr<<i<<"--------------\n";
//        for(auto u:e[i])cerr<<u<<" ";
//        cerr<<"\n";
//    }
//    cerr<<"---------------------\n";

    vector<int> dp(n+1,0),vis(n+1,0);
    vector<vector<int>> siz(n+1,vector<int>(2,0));
    auto dfs=[&](auto &&self,int u)->void {
        vis[u]=1;
//        cerr<<u<<"-------------------\n";
        int minn=INF,mi=INF,maxn=-INF;
        for(auto v:e[u]){
            self(self,v);
            maxn=max(maxn,v);
            if(minn==INF)minn=v;
            else if(mi==INF)mi=v;
            dp[v]+=siz[u][1]*siz[v][0];
//            cerr<<v<<" "<<siz[u][1]<<" "<<siz[v][0]<<" "<<dp[v]<<"\n";
            siz[u][1]+=siz[v][0];
            siz[u][0]++;
        }
        if(minn!=INF)dp[u]+=dp[minn];
        if(mi!=INF)dp[u]+=siz[mi][0]*(siz[u][0]-2);
        if(maxn==u-1){
            siz[u][0]+=siz[u][1];   
            // siz[u][1]=0;
        }
        if(mi!=INF)dp[u]+=siz[mi][0];
//        cerr<<u<<" "<<minn<<" "<<siz[u][0]<<" "<<siz[u][1]<<"=========\n";
        return;
    };
    for(int i=n;i>=1;i--)if(!vis[i])dfs(dfs,i);
    int ans=0;
//    cerr<<"===================\n";
    for(int i=1;i<=n;i++){
//        cerr<<i<<" "<<dp[i]<<"\n";
        ans+=dp[i];
    }
    cout<<ans<<"\n";
    // cerr<<"\n\n\n\n\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // freopen("migrate3.in","r",stdin);
    // freopen("code.out","w",stdout);
    int C,T=1;
    cin>>C;
    cin>>T;
    while(T--)solve();
    return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4

3

0 1
5 3
-3 0 2 3 4

2
*/
