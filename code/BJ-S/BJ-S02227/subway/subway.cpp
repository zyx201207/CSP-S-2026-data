#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int u,v;
    friend bool operator < (node a,node b){
        return a.v > b.v;
    }
};
vector <node> s1[505];
vector <node> s2[500005];
vector <node> s3[505];
int w[500005];
int d[505][505];
void solve(int st){
    priority_queue <node> q;
    q.push({st,0});
    while(q.size()){
        node now = q.top();
        q.pop();
        if(d[st][now.u] != 1e18) continue;
        d[st][now.u] = now.v;
        for(int i = 0;i < s3[now.u].size();i++){
            q.push({s3[now.u][i].u,now.v + s3[now.u][i].v});
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,q;
    cin >> c >> n >> m;
    cin >> c >> q;
    for(int i = 1;i <= m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i = 1;i <= n;i++){
        int num;
        scanf("%lld",&num);
        for(int j = 1;j <= num;j++){
            int u,v;
            scanf("%lld %lld",&u,&v);
            s1[i].push_back({u,v});
            s2[u].push_back({i,v});
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            d[i][j] = 1e18;
            if(i == j) d[i][j] = 0;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int now = 0;now < s1[i].size();now++){
            int x = s1[i][now].u;
            for(int j = 0;j < s2[x].size();j++){
                int y = s2[x][j].u;
                d[i][y] = min(d[i][y],s1[i][now].v + s2[x][j].v);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i != j && d[i][j] != 1e18) s3[i].push_back({j,d[i][j]});
            d[i][j] = 1e18;
        }
    }
    for(int i = 1;i <= n;i++){
        solve(i);
    }
    /*for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }*/
    while(q--){
        int u,v,ans = 1e18;
        scanf("%lld %lld",&u,&v);
        for(int i = 0;i < s2[u].size();i++){
            for(int j = 0;j < s2[v].size();j++){
                int x = s2[u][i].u,y = s2[v][j].u;
                ans = min(ans,w[u] + w[v] + s2[u][i].v + s2[v][j].v + d[x][y]);
                //cout << w[u] << " " << w[v] << " " << s2[u][i].v << " " << s2[v][j].v << " " << d[x][y] << " " << ans << endl;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
