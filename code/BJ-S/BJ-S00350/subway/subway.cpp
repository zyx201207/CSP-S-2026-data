#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, w[500005], s, t, x ,y, ti;
int const e = 1000000;
vector<pair<int, int>> p[1500005];
void bfs(int x, int y){
    queue<int> qu;
    bool vis[1500005]={0};
    int value[1500005]={0};
    qu.push(x);
    value[x]=0;
    while(!qu.empty()){
        int he = qu.front();
        qu.pop();
        if(he != y)vis[he]=true;
        for(int i = 0; i < p[he].size(); ++i){
            if(!vis[p[he][i].first]){
                qu.push(p[he][i].first);
                if(value[p[he][i].first]!=0) value[p[he][i].first]=min(value[p[he][i].first], value[he]+p[he][i].second);
                else value[p[he][i].first]=value[he]+p[he][i].second;
            }
        }
    }
    ti = value[y];
    return ;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i){
        cin >> k;
        while(k--){
            cin >> s >> t;
            p[s].push_back({i+e, t});
            p[i+e].push_back({s, t});
        }
    }
    while(q--){
        cin >> x >> y;
        bfs(x, y);
        cout<<ti+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}