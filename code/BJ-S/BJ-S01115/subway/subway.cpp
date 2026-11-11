#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int w[N];
struct node{
    int y,w;
};
vector<node>a[N];
int c,n,m,d,q;
priority_queue<pair<int,int>,vector <pair<int,int> >,greater<pair<int,int> > > pq;
int vis[N],dis[N];

void dij(int s){
    memset(vis,0,sizeof vis);
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    pq.push({0,s});
    while (!pq.empty()){
        int x = pq.top().second;
        pq.pop();
        if (vis[x] == 1) continue;
        vis[x] = 1;
        for (int i = 0; i < a[x].size(); i++){
            int y = a[x][i].y,w = a[x][i].w;
            //cout <<y <<" " <<s <<" " << x <<"\n";
            if (dis[y] > dis[x]+w){
                dis[y] = dis[x]+w;
                pq.push({dis[y],y});
            }
        }

    }
    //for (int i = 1; i <= m ; i++) cout << dis[i] <<"\n";
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >>m >>d >> q;
    int topid = m;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        int last = -1;
        while (k--){
            int id,t; cin >>id >> t;
            int myid = ++topid;
            //cout <<topid << "\n";
            if (last != -1){
                a[last].push_back({myid,0});
                a[myid].push_back({last,0});
                //cout << last << "<=>" << myid <<"\n";
            }
            //cout << id <<"<=> " << myid << " " << t <<"\n";
            a[myid].push_back({id,t});
            a[id].push_back({myid,t});
            last = myid;
        }
    }
    while (q--){
        int s,e; cin >>s >> e;
        dij(s);
        cout << dis[e]+w[s]+w[e] << "\n";
    }
    return 0;
}
