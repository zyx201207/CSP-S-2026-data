#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005];
int t[505][500005];
int k[505];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i=1; i<=m; i++){
        cin >> w[i];
    }

    vector<int> across[m+5];
    for(int i=1; i<=n; i++){
        cin >> k[i];
        for(int j=1; j<=k[i]; j++){
            cin >> a[i][j] >> t[i][a[i][j]];
            across[a[i][j]].push_back(i);
        }
    }

    //---------------init------------------
    vector<vector<long long>> adj(n+5,vector<long long> (n+5,LONG_MAX));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k[i]; j++){
            for(int s : across[a[i][j]]){
                if(s == i){
                    continue;
                }
                long long time = t[i][a[i][j]] +t[s][a[i][j]];
                if(time < adj[i][s]){
                    adj[i][s] = time;
                    adj[s][i] = time;
                }
            }
        }
    }

    int x,y;
    while(q--){
        cin >> x >> y;

        long long dist[n+5];
        bool visit[n+5];
        for(int i=0; i<n+5; i++){
            dist[i] = LONG_MAX;
            visit[i] = false;
        }
        dist[n+1] = 0;
        visit[n+1] = true;

        for(int s : across[x]){
            long long tx = w[x] + t[s][x];
            adj[n + 1][s] = tx;
        }

        for(int s : across[y]){
            long long ty = w[y] + t[s][y];
            adj[s][n+2] = ty;
        }

        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>> que;
        for(int s : across[x]){
            que.push({adj[n+1][s],{n+1,s}});
        }

        while(!que.empty()){
            long long value = que.top().first;
            int s = que.top().second.second;
            int s0 = que.top().second.first;
            if(visit[s]){
                que.pop();
                continue;
            }
            if(value + dist[s0] < dist[s]){
                dist[s] = value + dist[s0];
                que.pop();
                visit[s] = true;
                for(int i=1; i<=n+2; i++){
                    if(visit[i]){
                        continue;
                    }
                    if(adj[s][i] != LONG_MAX){
                        que.push({adj[s][i],{s,i}});
                    }
                }
            }
        }
        cout << dist[n+2] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
