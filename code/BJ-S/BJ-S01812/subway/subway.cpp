#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n,m,c,q,d,w[N],T[N][N],ans;
vector<int>g[N],f[N];
bool check(int x,int y){
    for(int i = 1;i <= f[x].size();i++){
        for(int j = 1;j <= f[y].size();j++){
            if(f[i] == f[j]){
                return 1;
            }
        }
    }
    return 0;
}
int bfs(int s,int t){
    queue<int>q;
    bool vis[N] = {};
    q.push(s);
    int st = f[s][0];
    int ans = w[s] + T[st][s] + w[t];
    //printf("%d ",ans);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            int cur = 0;
            if(!vis[v]){//dis=-1
                q.push(v);
                vis[v] = 1;
                //printf("%d ",f[v]);
                if(!f[v].empty() && f[v][0] != st){
                    int i = f[u][0],j = f[v][0];//,j = i,j,u,vf[v][0]; %d %d
                    cur += T[i][u] + T[j][u];
                    st = f[v][0];
                    //printf("%d %d \n",T[i][u],T[j][u]);
                }
            }
            ans += (cur == 1e9 ? 0 : cur);
            if(v == t){
                ans += T[st][t];
                return ans;
            }

        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
    int mx = -1e9;
    for(int i = 1;i <= n;i++){
        int k;
        scanf("%d",&k);
        for(int j = 1;j <= k;j++){
            int a;
            scanf("%d",&a);
            scanf("%d",&T[i][a]);
            f[a].push_back(i);
            g[j].push_back(a);//sort
            g[a].push_back(j);
            mx = max(mx,a);
        }
    }
    //puts("\n");
    /*for(int i = 1;i <= mx;i++){
        printf("%d : ",i);
        for(int j = 0;j < f[i].size();j++){
            printf("%d ",f[i][j]);
        }
        puts("\n");
    }*/
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",bfs(x,y));
    }
    return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
