/*
graph theory
---
rewrite:
there are three layers
and some complicated edges
q queries, each of which questions
the minimum distance between u,v
---
attention that the edges between 
entrance and lobby(?) is useless
---
there is a property that in a path,
every line will be passed at most one time.
---
i have no idea
let me think about the spp
A: lines that only passes one station are useless
and every line passes at most two station
so you can directly connect the stations
then run the floyd
---
ok now i have some idea
i once did a exercise 
in which you need to turn a edge into a point
i think this problem maybe the same
we turn a line into a point(?)
the edges are those transfering station
and weights are sums
the total time complexity is
O(n^3+qd^2)
1.65e8
i hope the ccf's machine is fast enough
---
procedure:

pre-process:
get the input
scan every point, calculate the distance between every lines
run the floyd

process:
for every query
scan the lines and find the mininum distance
output the answer.

seems reasonable
time:16:18
*/

#include<bits/stdc++.h>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=505;
const int M=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int kase,n,m,d,q;
ll w[M],dis[N][N];
vector<pll> e[M];

void input(){
    cin>>kase>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            e[a].push_back({i,t});
        }
    }
}

void calc(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) dis[i][j]=inf;
    for(int i=1;i<=m;i++){
        int siz=e[i].size();
        for(int j=0;j<siz;j++)
            for(int k=j+1;k<siz;k++){
                int u=e[i][j].fi,v=e[i][k].fi;
                dis[u][v]=dis[v][u]=e[i][j].se+e[i][k].se;
            }
    }
}

void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<dis[i][j]<<' ';
    //     cout<<'\n';
    // }
}

void solve(){
    int u,v;
    cin>>u>>v;
    ll sum=inf;
    for(pll tu:e[u])
        for(pll tv:e[v])
            sum=min(sum,tu.se+tv.se+dis[tu.fi][tv.fi]);
    cout<<sum+w[u]+w[v]<<'\n';
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    input();
    calc();
    floyd();
    while(q--) solve();
    return 0;
}
/*
code by A.Y.C.
awa
code completion and clapping are on 16:50
*/