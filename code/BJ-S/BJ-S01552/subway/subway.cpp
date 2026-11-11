#include <bits/stdc++.h>
using namespace std;


const int N = 500+10;
long long c,n,m,d,q,w[N],k[510],t[510][N],a[510][N],dis[510][N];
struct node{
    long long tof,to,w;
};
vector<pair<int,int>>dic[N];
vector<node>v[510][N];

bool operator<(node x,node y){
    return x.w > y.w;
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    priority_queue<node>q;
    for(auto i:dic[s]){
        dis[i.first][i.second] = w[a[i.first][i.second]]+t[i.first][i.second];
        q.push({i.first,i.second,dis[i.first][i.second]});
    }
    while(!q.empty()){
        int tof = q.top().tof,to = q.top().to,w = q.top().w;
        cout << tof <<" "<<to<<" "<<w<<"\n";
        q.pop();
        if(w != dis[tof][to]){
            cout << "continue!!\n";
            continue;
        }
        for(auto i:v[tof][to]){
            if(dis[i.tof][i.to] > dis[tof][to]+i.w){
                dis[i.tof][i.to] = dis[tof][to]+i.w;
                q.push({i.tof,i.to,dis[i.tof][i.to]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];//出战时间（只考虑起点和终点)
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
            if(j != 1){
                v[i][j].push_back({i,j-1,0});
                v[i][j-1].push_back({i,j,0});
            }
            for(auto ac:dic[a[i][j]]){
                v[i][j].push_back({ac.first,ac.second,t[i][j]+t[ac.first][ac.second]});
                v[ac.first][ac.second].push_back({i,j,t[i][j]+t[ac.first][ac.second]});
            }
            dic[a[i][j]].push_back({i,j});
        }
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= m;i++){
            for(auto ac:v[k][i]){
                cout <<"floor:"<<k<<" "<<"node:"<<a[k][i]<<" to:"<<"floor:"<<ac.tof<<" "<<"node:"<<a[ac.tof][ac.to]<<" weight:"<<ac.w<<endl;
            }
        }
    }

    while(q--){
        int s , e;
        cin >> s >> e;
        dijkstra(s);
        long long ans = 1e15;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k[i];j++){
                if(a[i][j] == e){
                    ans = min(ans,dis[i][j]+w[e]+t[i][j]);
                }
            }
        }
        cout <<ans << endl;
    }
    return 0;
}
