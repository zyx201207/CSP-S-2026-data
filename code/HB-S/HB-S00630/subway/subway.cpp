#include<bits/stdc++.h>
using namespace std;

#define var long long
#define ln '\n'
#define Pt(x) fixed<<setpericison(x)
#define strsiz(x) (var)(x.size())

const var MaxM=5e5+10;
const var MaxN=510;
var c,n,m,d,q,cnt;
var w[MaxM];
vector<pair<var,var> > edge[MaxM+MaxN];
var dist[MaxM+MaxN];
bool vis[MaxM+MaxN];

var dijkstra(var s,var t){
    fill(dist+1,dist+1+cnt,INT_MAX);
    fill(vis+1,vis+1+cnt,0);
    priority_queue<pair<var,var>,vector<pair<var,var> >,greater<pair<var,var> > > que;

    dist[s]=0;
    que.push({0,s});

    while(que.size()){
        var u=que.top().second;
        que.pop();

        if(vis[u]) continue;
        vis[u]=true;

        if(u==t){
            return dist[u];
        }

        for(auto it:edge[u]){
            var v=it.first;
            var w=it.second;

            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                que.push({dist[v],v});
            }
        }
    }
    return -1;
}

var bfs(var s,var t){
    fill(dist+1,dist+1+cnt,INT_MAX);
    fill(vis+1,vis+1+cnt,0);
    queue<pair<var,var> > que;

    dist[s]=0;
    que.push({0,s});

    while(que.size()){
        var u=que.front().second;
        que.pop();

        if(vis[u]) continue;
        vis[u]=true;

        if(u==t){
            return dist[u];
        }

        for(auto it:edge[u]){
            var v=it.first;
            var w=it.second;

            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                que.push({dist[v],v});
            }
        }
    }
    return -1;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>n>>m>>d>>q;
    cnt=m;

    for(var i=1;i<=m;i++){
        cin>>w[i];
    }

    for(var i=1;i<=n;i++){
        var k;
        cin>>k;

        cnt++;
        for(var j=1;j<=k;j++){
            var a,t;
            cin>>a>>t;

            edge[a].push_back({cnt,t});
            edge[cnt].push_back({a,t});
        }
    }

    while(q--){
        var s,t;
        cin>>s>>t;

        if((c>=16 && c<=19) || true) cout<<w[s]+w[t]+bfs(s,t)<<ln;
        else cout<<w[s]+w[t]+dijkstra(s,t)<<ln;
    }
    return 0;
}
/*
g++ subway.cpp -o subway.exe -O2 -std=c++14
./subway.exe < subway1.in > subway.out
diff subway1.ans subway.out
./subway.exe < subway2.in > subway.out
diff subway2.ans subway.out
./subway.exe < subway3.in > subway.out
diff subway3.ans subway.out
./subway.exe < subway4.in > subway.out
diff subway4.ans subway.out
./subway.exe < subway5.in > subway.out
diff subway5.ans subway.out
./subway.exe < subway6.in > subway.out
diff subway6.ans subway.out
./subway.exe < subway7.in > subway.out
diff subway7.ans subway.out


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

16 2 5 1000 2
1 1 1 1 1
3 1 1 2 1 3 1
4 2 1 3 1 4 1 5 1
1 4
2 5
*/