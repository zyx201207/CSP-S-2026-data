#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+8;
int x[N];
int c,_,n,d;
bool ust[N][N];
int cnt[N][N];
int dis[N][N];

struct node{
    int v,w;
};

struct no{
    int v,w;
};

vector <node> adj[N];

void bfs(int s, int t){
    queue<node> q;
    q.push({s,0});

    while(q.size()){
        int u = q.front().v;
        int stp=q.front().w;
        q.pop();
        if(u == t){
            //cout << s << " " << t << " "<<stp << " "<<endl;
            if(dis[s][t] == stp) cnt[s][t]++;
            else if(dis[s][t] > stp){
                cnt[s][t] = 1;
                dis[s][t] = stp;
            }


        }
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].v,w = adj[u][i].w;
            //cout<<"each:" << u << " "<<v << " "<<stp+w<< endl;
            q.push({v,stp+1});
        }
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> _;
    while(_--){
        for(int i = 1; i <= n; i++) adj[i].clear();
        memset(dis,0x3f,sizeof(dis));
        //memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(abs(x[i]-x[j]) <= d){
                    adj[i].push_back({j,abs(x[i]-x[j])});
                    //adj[j].push_back({i,abs(x[i]-x[j])});
                }
            }
        }


        int ans = 0;
        for(int s = 1; s <= n;s++){
            for(int t = s+1; t <= n; t++){
                //cout <<"aim:"<< s << " " << t << endl;
                bfs(s,t);
                //cout <<"cnt:"<<cnt[s][t]<<endl;
                if(cnt[s][t] == 2) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
