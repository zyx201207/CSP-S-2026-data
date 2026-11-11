#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int M = 5e2 + 5;
int w[N];
int k[M];
vector<int> a[N], t[N], vt[M];// fang MLE
bool vis1[M], vis2[N];
int n, m, c, d, Q;
int num;
int start, last;
queue<int> q;
int dis[N];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> Q;
    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    for(int i=1; i<=n; i++){
            cin >> k[i];
        for(int j = 1; j <= k[i]; j++){
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            vt[x].push_back(i);
        }
    }
    while(Q--){
        cin >> start >> last;
        for(int i=1; i<=n; i++){
            dis[i] = 0;
            vis1[i] = 0;
            vis2[i] = 0;
        }
        q.push(start);
        vis2[start] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u=0; u<vt[v].size(); u++){
                int i=vt[v][u];
                if(vis1[i] == 0){
                    vis1[i] = 1;
                    for(int j=0; j<a[i].size(); j++){
                        int x = t[i][j], y = a[i][j];
                        if(vis2[y] == 0){
                            vis2[y] = 0;
                            q.push(y);
                            dis[y] = dis[v] + x;
                        }
                    }
                }
            }
        }
        cout << dis[last] + w[start] + w[last] << endl;
    }
    return 0;
}
