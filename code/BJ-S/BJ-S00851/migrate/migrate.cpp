#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1e5 + 5;
#define int long long
int c = 0,t = 0;
int n = 0,d = 0;
int w[maxn];
int x[maxn];
struct node{
    int u;
    int w;
    bool operator<(const node& other)const{
        return w > other.w;
    }

};
vector<node>p[maxn];
int dis[maxn];
int vis[maxn];
bool check(int l,int r){
    for(int i = 1;i <= n;i++){
        dis[i] = 1e18;
        vis[i] = 0;
    }
    dis[l] = 0;
    priority_queue<node>q;
    q.push({l,0});
    int ans = 1e18;
    while(!q.empty()){
        node tmp = q.top();
        q.pop();
        int u = tmp.u;
        for(int i = 0;i < p[i].size();i++){
            int v= p[u][i].u;
            int w=p[u][i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({v,dis[v]});
            }
        }
    }
    int cnt = 0;
    q.push({l,0});
    while(!q.empty()){
        node tmp = q.top();
        q.pop();
        int u = tmp.u;
        int step = tmp.w;
        if(u == r){
            if(step == dis[r]) cnt++;
            continue;
        }
        for(int i = 0;i < p[i].size();i++){
            int v= p[u][i].u;
            int w=p[u][i].w;
            q.push({v,step + w});
        }
    }
    return (cnt == 2);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1; i<= n;i++) cin>>x[i];
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(i != j && abs(x[i] - x[j]) <= d){
                    p[i].push_back({j,abs(x[i] - x[j])});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <=n;j++){
                if(check(i,j)){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
