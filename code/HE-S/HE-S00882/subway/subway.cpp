#include <bits/stdc++.h>
using namespace std;

const int MAX_N=5e2;
const int MAX_M=5e5;
using ll=long long;

struct edge{

    int to;
    ll value;
    edge(){}
    edge(int n_to, ll n_value){
        to=n_to, value=n_value;
    }

};

int c, n, m, d, q;
ll w[MAX_M+10];
vector <edge> from[MAX_N+MAX_M+10];
ll dis[MAX_M+MAX_N+10];
set < pair <ll, int> > h;
queue <int> qu;

ll dijkstra(int s, int t){

    memset(dis, 127, sizeof(dis));
    dis[s]=0;
    h.clear();
    for(int i=1; i<=n+m; i++){
        h.insert({dis[i], i});
    }
    while(!h.empty()){
        ll first=h.begin()->first;
        int second=h.begin()->second;
        h.erase(h.begin());
        if(second==t)  return first;
        for(auto i : from[second]){
            if(dis[i.to]>dis[second]+i.value){
                h.erase({dis[i.to], i.to});
                dis[i.to]=dis[second]+i.value;
                h.insert({dis[i.to], i.to});
            }
        }
    }
    return -1;

}

ll bfs(int s, int t){

    memset(dis, -1, sizeof(dis));
    for(; !qu.empty(); qu.pop());
    dis[s]=0;
    qu.push(s);
    while(!qu.empty()){
        int f=qu.front();
        if(f==t)    return dis[t];
        qu.pop();
        for(auto i : from[f]){
            if(dis[i.to]!=-1)   continue;
            dis[i.to]=dis[f]+i.value;
            qu.push(i.to);
        }
    }
    return dis[t];

}

int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i=1; i<=m; i++){
        scanf("%lld", &w[i]);
    }
    for(int i=1; i<=n; i++){
        int num=0;
        scanf("%d", &num);
        for(int j=1; j<=num; j++){
            int to=0;
            ll value=0;
            scanf("%d%lld", &to, &value);
            from[m+i].push_back(edge(to, value));
            from[to].push_back(edge(m+i, value));
        }
    }
    for(int i=1; i<=q; i++){
        int x=0, y=0;
        scanf("%d%d", &x, &y);
        if(12<=c && c<=19){
            printf("%lld\n", bfs(x, y)+w[x]+w[y]);
        }else{
            printf("%lld\n", dijkstra(x, y)+w[x]+w[y]);
        }
    }

    return 0;

}
