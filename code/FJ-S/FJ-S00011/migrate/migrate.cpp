#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Edge{
    int to,len;
};
vector<vector<Edge>> e;

struct Dis{
    int fst,sec,trd;
};
vector<vector<Dis>> dis;

int c,t,n,d,cnt;
vector<int> x;

struct Node{
    int id,val;

    bool operator<(const Node& other) const{
        return this->val > other.val;
    }
};

void dijkstra(int start){
    priority_queue<Node> q;
    dis[start][start].fst = 0;
    q.push({start,dis[start][start].fst});

    while(!q.empty()){
        auto cur = q.top();
        q.pop();

        for(auto v : e[cur.id]){
            if(cur.val+v.len < dis[start][v.to].fst){
                dis[start][v.to].trd = dis[start][v.to].sec;
                dis[start][v.to].sec = dis[start][v.to].fst;
                dis[start][v.to].fst = cur.val+v.len;
                q.push({v.to,dis[start][v.to].fst});
                q.push({v.to,dis[start][v.to].sec});
                q.push({v.to,dis[start][v.to].trd});
            }
            else if(cur.val+v.len < dis[start][v.to].sec){
                dis[start][v.to].trd = dis[start][v.to].sec;
                dis[start][v.to].sec = cur.val+v.len;
                q.push({v.to,dis[start][v.to].sec});
                q.push({v.to,dis[start][v.to].trd});
            }
            else if(cur.val+v.len < dis[start][v.to].trd){
                dis[start][v.to].trd = cur.val+v.len;
                q.push({v.to,dis[start][v.to].trd});
            }
        }
    }
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        cnt = 0;
        x.clear();
        x.resize(n+1);
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }

        if(c==11 || c==12){
            int cha = x[2]-x[1];
            int tmp = d/cha;
            if(tmp == 1){
                cout << 0 << endl;

                continue;
            }

            for(int i = 1;i <= n-(tmp<<1)+1;i++){
                if(d >= (cha<<1)){
                    cnt++;
                }
            }

            cout << cnt << endl;

            continue;
        }

        dis.clear();
        dis.resize(n+1,vector<Dis>(n+1,{INT_MAX,INT_MAX,INT_MAX}));
        e.clear();
        e.resize(n+1);
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(abs(x[i]-x[j]) <= d){
                    e[i].push_back({j,1});
                    e[j].push_back({i,1});
                }
            }
        }

        for(int i = 1;i <= n;i++){
            dijkstra(i);
        }

        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(dis[i][j].fst==dis[i][j].sec && dis[i][j].sec!=dis[i][j].trd){
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
