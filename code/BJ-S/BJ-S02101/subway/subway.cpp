#include <bits/stdc++.h>
using namespace std;
#define int long long

int read(){
    int k = 0,f = 1;
    char c = getchar_unlocked();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar_unlocked();
    }
    while('0' <= c && c <= '9'){
        k = k * 10 + c - '0';
        c = getchar_unlocked();
    }
    return k * f;
}

const int N = 505;
const int M = 5e5 + 10;

struct node{
    int id,t;
};

int c,n,m,d,q,w[M],dis[N][N];
vector<node> v[M];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    c = read(),n = read(),m = read(),d = read(),q = read();

    for(int i = 1;i <= m;i++){
        w[i] = read();
    }

    for(int i = 1;i <= n;i++){
        int k = read();
        for(int j = 1;j <= k;j++){
            int a = read(),t = read();
            v[a].push_back({i,t});
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dis[i][j] = 2e18;
        }
        dis[i][i] = 0;
    }

    for(int i = 1;i <= m;i++){
        for(int j = 0;j < v[i].size();j++){
            for(int k = j + 1;k < v[i].size();k++){
                dis[v[i][j].id][v[i][k].id] = min(dis[v[i][j].id][v[i][k].id],v[i][j].t + v[i][k].t);
                dis[v[i][k].id][v[i][j].id] = min(dis[v[i][k].id][v[i][j].id],v[i][j].t + v[i][k].t);
            }
        }
    }

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }

    while(q--){
        int x = read(),y = read(),ans = 2e18;
        for(int i = 0;i < v[x].size();i++){
            for(int j = 0;j < v[y].size();j++){
                ans = min(ans,dis[v[x][i].id][v[y][j].id] + v[x][i].t + v[y][j].t);
            }
        }
        printf("%lld\n",ans + w[x] + w[y]);
    }

    return 0;
}