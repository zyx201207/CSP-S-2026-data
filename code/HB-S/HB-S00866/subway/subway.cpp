#include <bits/stdc++.h>
using namespace std;
const int maxm = 5007;
struct node{
    int w,l;
};
map <int,int> mp1[maxm];
map <int,int> mp2[maxm];
vector <node> p[maxm];
int w[maxm];
int ans[maxm][maxm];
int ss[maxm];
int k;
int c,n,m,d,r;
int dis[maxm];
bool vis[maxm];
void dijikestra(int s){
    priority_queue <pair <int,pair <int,int> >,vector <pair <int,pair <int,int> > >,greater <pair <int,pair <int,int> > > > pq;
    for (int i = 1;i <= m;i++) dis[i] = INT_MAX;
    for (int i = 1;i <= m;i++) vis[i] = 0;
    dis[s] = 0;
    pq.push({dis[s],{s,0}});
    while (!pq.empty()){
        int u = pq.top().second.first;
        int line = pq.top().second.second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (node v : p[u]){
            int to = v.w;
            int line2 = v.l;
            if (dis[u]+mp1[line][u]+mp2[u][line2] < dis[to]){
                dis[to] = dis[u]+mp1[line][u]+mp2[u][line2];
                pq.push({to,{dis[to],line2}});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> n >> m >> d >> r;
    for (int i = 1;i <= m;i++) cin >> w[i];
    for (int i = 1;i <= n;i++){
        cin >> k;
        int lt = 0;
        while (k--){
            int x,t;
            cin >> x >> t;
            mp1[i][x] = t;
            mp2[x][i] = t;
            ss[x] = t;
        }
    }
    while (r--){
        int ll,rr;
        cin >> ll >> rr;
        cout << w[ll]+ss[ll]+w[rr]+ss[rr] << '\n';
    }
    return 0;
}
