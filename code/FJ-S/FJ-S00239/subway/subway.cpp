#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int Q = 1e5 + 5;
struct node{
    int pos;
    long long dis;
    bool operator < (const node &s) const{
        return s.dis < dis;
    }
};
unordered_map <int,int> idx;
#define mark(pos,d) ((pos - 1) * m + d)
#define marks(pos,d) idx[mark(pos,d)]
vector <pair<int,long long>> e[N];
unordered_map <int,long long> dis[N];
unordered_map <int,bool> srr;
long long w,t,k;
bool vis[N];
int n,m,c,d,qr,x,y,cnt,a,lsta;
inline void dijkstra(int s){
    memset(vis,0,sizeof(vis)),srr.clear(),dis[s].clear();
    dis[s][s] = 0,srr[s] = true;
    priority_queue <node> q;
    q.push({s,0});
    while (!q.empty()){
        node x = q.top();
        q.pop();
        if (!srr[x.pos]) dis[s][x.pos] = 0x3f3f3f3f3f3f3f3f,srr[x.pos] = true;
        if (vis[x.pos]) continue;
        vis[x.pos] = true;
        for (pair <int,long long> i:e[x.pos]){
            if (!srr[i.first]) dis[s][i.first] = 0x3f3f3f3f3f3f3f3f,srr[i.first] = true;
            if (dis[s][i.first] > dis[s][x.pos] + i.second){
                dis[s][i.first] = dis[s][x.pos] + i.second;
                if (!vis[i.first]) q.push({i.first,dis[s][i.first]});
            }
        }
    }
}
char ch;
inline void read(int &x){
    x = 0,ch = getchar();
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48),ch = getchar();
}
inline void read(long long &x){
    x = 0,ch = getchar();
    while (!(ch >= '0' && ch <= '9')) ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48),ch = getchar();
}
unordered_map <int,int> xs;
unordered_map <int,int> ys;
int qsx[Q],qsy[Q],cntx,cnty;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(c),read(n),read(m),read(d),read(qr);
    for (int i = 1;i <= m;++i){
        read(w);
        idx[mark(1,i)] = ++cnt,idx[mark(2,i)] = ++cnt;
        e[cnt].push_back({cnt - 1,w}),e[cnt - 1].push_back({cnt,w});
    }
    for (int i = 1;i <= n;++i){
        read(k);
        for (int j = 1;j <= k;++j){
            read(a),read(t);
            idx[mark(i + 2,a)] = ++cnt,e[cnt].push_back({marks(2,a),t}),e[marks(2,a)].push_back({cnt,t});
            if (j != 1) e[marks(i + 2,lsta)].push_back({cnt,0}),e[cnt].push_back({marks(i + 2,lsta),0});
            lsta = a;
        }
    }
    for (int i = 1;i <= qr;++i){
        read(qsx[i]),read(qsy[i]);
        if (!xs[qsx[i]]) ++cntx,xs[qsx[i]] = true;
        if (!ys[qsy[i]]) ++cnty,ys[qsy[i]] = true;
    }
    if (cntx < cnty){
        for (pair <int,bool> i:xs) dijkstra(marks(1,i.first));
        for (int i = 1;i <= qr;++i) cout << dis[marks(1,qsx[i])][marks(1,qsy[i])] << "\n";
    }else{
        for (pair <int,bool> i:ys) dijkstra(marks(1,i.first));
        for (int i = 1;i <= qr;++i) cout << dis[marks(1,qsy[i])][marks(1,qsx[i])] << "\n";
    }
    return 0;
}