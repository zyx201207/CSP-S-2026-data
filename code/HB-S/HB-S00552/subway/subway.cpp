#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int MAXN = 500005;
const int INF = 1e9;
int c,n,m,d,q;
int w[MAXN];//time from exit to station
int up[MAXN];
int k[500005][22];//time from station to platform
vector<pair<int,int>> g[MAXN];//first -> dot connected;second -> train number
vector<int> dist;
int dot_now_in[MAXN];
int s,e;
int diji(int s){
    dist.assign(MAXN,INF);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    //1.time,2.now station,3.train number
    pq.push(mp(0,mp(s,0)));
    dist[s] = 0;
    while(!pq.empty()){
        auto x = pq.top();
        int time_used = x.first;
        int u = x.second.first;
        int cur = x.second.second;
        pq.pop();
        for(pair<int,int> fetch : g[u]){
            time_used = x.first;
            int v = fetch.first;
            int nxtr = fetch.second;
            int chk = dist[v];
            if(nxtr != cur){
                time_used += k[u][cur] + k[u][nxtr];
            }
            if(dot_now_in[v] != nxtr) chk = dist[v] + k[v][dot_now_in[v]] + k[v][nxtr];
            if(chk > time_used){
                dist[v] = time_used;
                up[v] = nxtr;
                dot_now_in[v] = nxtr;
                pq.push(mp(time_used,mp(v,nxtr)));
            }
        }
    }
    return up[e];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        int ki;
        cin >> ki;
        int pre = 0;
        for(int j = 1;j <= ki;j++){
            int a,t;
            cin >> a >> t;
            if(j >= 2){
                g[pre].push_back({a,i});
                g[a].push_back({pre,i});
            }
            pre = a;
            k[a][i] = t;
        }
    }
    int pres;
    for(int i = 1;i <= q;i++){
        cin >> s >> e;
        if(pres != s) int uptr = diji(s);
        pres = s;
        cout << w[s] + dist[e] + w[e] + k[e][uptr] << '\n';
    }
    return 0;
}
