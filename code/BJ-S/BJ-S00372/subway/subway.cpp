#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
int n, m, k, q, addi[500005];
long long dist[500505];
bool vis[500505];
vector<PII>edges[500505];
priority_queue<PII, vector<PII>, greater<PII> >que;

void dij(int src){
    que.push({0, src});
    while(!que.empty()){
        PII tp = que.top();
        que.pop();
        if(vis[tp.second])continue;
        vis[tp.second] = true;
        for(PII a : edges[tp.second]){
            if(dist[a.second] <= a.first + tp.first)continue;
            dist[a.second] = a.first + tp.first;
            que.push({dist[a.second], a.second});
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%*d%d%d%*d%d", &n, &m, &q);
    for(int i = 1; i <= m; i++){
        scanf("%d", &addi[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);
        for(int j = 1; j <= k; j++){
            int a, w;
            scanf("%d%d", &a, &w);
            edges[a].push_back({w, m + i});
            edges[m + i].push_back({w, a});
        }
    }
    for(int i = 1; i <= q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        memset(dist, 127, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        dij(a);
        printf("%lld\n", dist[b] + addi[a] + addi[b]);
    }
    return 0;
}
