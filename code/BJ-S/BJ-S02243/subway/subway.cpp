#include <bits/stdc++.h>
using namespace std;
const int M = 700005;
int tot,c,n,m,d,q,k,w[M],a,t;
int st,ed;
long long dis[M];
int read(){
    int x = 1,ret = 0;
    char c = getchar();
    while(c < '0' ||  c > '9'){
        if(c == '-')x = -1;
        c = getchar();
    }
    while(c >= '0' &&c <= '9'){
        ret = ret*10+c-'0';
        c = getchar();
    }
    return ret*x;
}
struct edge{
    int to,val;

};
struct node{
    int id,siz;
    friend bool operator <(node a, node b){
        return a.siz > b.siz;
    }
};
vector <edge> v[M];
long long dijk(int st, int ed){
    priority_queue <node> pq;
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    pq.push({st,0});
    while(pq.size()){
        int pos = pq.top().id;
        pq.pop();
        for(int i = 0; i < v[pos].size(); i++){
            int to = v[pos][i].to;
            int val = v[pos][i].val;
            if(dis[to] > dis[pos]+val){
                dis[to]=dis[pos]+val;
                pq.push({to,dis[pos]});
            }
        }
    }
    return dis[ed];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    c=read();n=read();m=read();d=read();q=read();
    tot=m;
    for(int i = 1; i <= m; i++){
        w[i]=read();
    }
    for(int i = 1; i <= n; i++){
        k=read();
        int pos = ++tot;
        for(int j = 1; j <= k; j++){
            a = read();
            t = read();
            v[a].push_back({pos,t});
            v[pos].push_back({a,t});
        }
    }
    while(q--){
        st = read();
        ed = read();
        cout << dijk(st,ed)+w[st]+w[ed] <<endl;
    }
    return 0;
}