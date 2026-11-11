#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3+10;
ll c,n,m,d,q,w[N],dis[N],k[N],a[N][505],vis[N][505],t[N][505];
struct node{
    ll v,id;
};
vector <node> g[N];
vector <int> G[N];
ll F(int x,int y){
    memset(dis,0x3f3f3f3f,sizeof dis);
    queue <node> q;
    for(int i = 0;i < G[x].size();i++){
        q.push({x,G[x][i]});
    }
    while(q.size()){
        node u = q.front();
        q.pop();
        if(vis[u.v][u.id]) continue;
        vis[u.v][u.id] = 1;
        for(int i = 0;i < g[u.v].size();i++){
            int v = g[u.v][i].v,id = g[u.v][i].id;
            if(id == u.id){
                if(dis[v] > dis[u.v]){
                    dis[v] = dis[u.v];
                    q.push({v,id});
                }
            }
            else{
                if(dis[u.v]+t[u.v][u.id]+t[u.v][id] < dis[v]){
                    dis[v] = dis[u.v]+t[u.v][u.id]+t[u.v][id];
                    q.push({v,id});
                }
            }
        }
    }
    return dis[y];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            G[a[j][i]].push_back(i);
            cin >> a[j][i] >> t[j][i];
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        cout << k[i] << " ";
        for(int j = 1;j <= k[i];j++){
            cout << a[j][i] << " " << t[j][i] << " ";
        }
        cout <<endl;
    }
    */
    for(int i = 1;i <= n;i++){
        for(int x = 1;x <= k[i];x++){
            for(int y = x+1;y <= k[i];y++){
                //cout << a[x][i] << " " << a[y][i] << endl;
                g[a[y][i]].push_back({a[x][i],i});
                g[a[x][i]].push_back({a[y][i],i});
            }
        }
        //cout << endl;
    }
/*

    for(int i = 1;i <= m;i++){
            cout << i << ':';
        for(int j = 0;j < gg[i].size();j++){
            cout << gg[i][j].v << "#" << gg[i][j].id << " ";
        }
        cout << endl;
    }*/

    while(q--){
        int xx,yy;
        cin >> xx >> yy;
        cout << F(xx,yy) << endl;
    }

    return 0;
}

