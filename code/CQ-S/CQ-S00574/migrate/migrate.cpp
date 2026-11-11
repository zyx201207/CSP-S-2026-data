#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<long long,long long>
#define mp make_pair
using namespace std;
const long long N=1e6+50;
long long c,T;
long long n;
__int128 d;
__int128 x[N];
long long num[N];
long long dis[N];
pii dp[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
void init_for(){
    for(int i=1;i<=n;i++)dp[i]=mp(inf,inf);
    for(int i=0;i<=n;i++)num[i]=0;
    if(!q.empty())q.pop();
}
vector<int> vec[N];
void bfs(int s,long long &ans){
    for(int i=1;i<=n;i++)dis[i]=-1,num[i]=0;
    queue<int> q;
    dis[s]=0,num[s]=1;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(num[u]==2 && u!=s)ans++;
        // cerr<<u<<" "<<num[u]<<"\n";
        for(int v:vec[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                num[v]=num[u];
                q.push(v);
            }else if(dis[v]==dis[u]+1){
                num[v]+=num[u];
            }
        }
    }
}
void solveB(){
    for(int i=1;i<=n;i++)vec[i].clear();
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]>d)break;
            vec[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        bfs(i,ans);
    }
    cout<<ans<<'\n';
}
void solveA(){
    long long ans=0;
    // for(int i=1;i<=n;i++){
    //     init_for();
    //     dp[i]=mp(0,1);
    //     num[0]+=dp[i].second;
    //     q.push(mp(0,i));
    //     long long l=i;
    //     for(int j=i-1;j>=1;j--){
    //         while(l>=1 && x[l]-x[j]>d){
    //             num[dp[l].first]-=dp[l].second;
    //             l--;
    //         }
    //         while(!q.empty() && q.top().second>l)q.pop();
    //         if(!q.empty()){
    //             dp[j]=mp(q.top().first+1,num[q.top().first]);
    //             q.push(mp(dp[j].first,j));
    //             num[dp[j].first]+=dp[j].second; 
    //             if(dp[j].first!=0 && dp[j].second==2)ans++;
    //         }else break;
    //     }
    // }
    for(int i=1;i<=n;i++){
        init_for();
        dp[i]=mp(0,1);
        num[dp[i].first]+=dp[i].second;
        q.push(mp(dp[i].first,i));
        long long l=i;
        for(int j=i+1;j<=n;j++){
            // cerr<<l<<" "<<j<<" "<<x[j]-x[l]<<'\n';
            while(l<=j && x[j]-x[l]>d){
                // cerr<<j<<" "<<l<<" "<<x[j]-x[l]<<'\n';
                num[dp[l].first]-=dp[l].second;
                l++;
            }
            if(l>=j)break;
            while(!q.empty() && q.top().second<l)q.pop();
            dp[j]=mp(q.top().first+1,num[q.top().first]);
            num[dp[j].first]+=dp[j].second;
            q.push(mp(dp[j].first,j));
            if(dp[j].second==2){
                // cerr<<i<<" "<<j<<'\n';
                // cerr<<dp[j].first<<" "<<dp[j].second<<'\n';
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
void solve(){
    unsigned long long tmp;
    cin>>n>>tmp;
    d=tmp;
    for(long long i=1,u;i<=n;i++){
        cin>>u;
        x[i]=u;
    }
    if(n<=300)solveB();
    else solveA();
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        // cerr<<"T "<<T<<'\n';
        solve();
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
-4 -3 -2 -1 3 6
0
*/