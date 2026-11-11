#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int C,T,n,k;
vector<int> G[MAXN];
bool vis[MAXN];
int dis[MAXN];

void cleanup(){
    for (int i = 1;i <= n;i ++)G[i].clear();
}

void dfs(int x,int fa,int S){
    vis[x] = true;
    for (auto y : G[x]){
        if (y == fa)continue;
        if (!(S >> (y - 1) & 1))continue;
        dfs(y,x,S);
    }
}

int main(){
    #ifndef kevin
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif
    scanf("%d%d",&C,&T);
    while (T --){
        scanf("%d%d",&n,&k);
        for (int i = 1;i < n;i ++){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int ans = 0x3f3f3f3f;
        for (int S = 0;S < (1 << n);S ++){
            if (__builtin_popcount(S) != k)continue;
            for (int i = 1;i <= n;i ++)vis[i] = 0;
            int ltk = 0;
            for (int i = 1;i <= n;i ++)
                if ((S >> (i - 1) & 1) && !vis[i]){
                    ltk ++;
                    dfs(i,0,S);
                }
            // printf("S %d ltk %d\n",S,ltk);
            if (ltk >= 3)continue;
            // printf("dudu\n");
            queue<int> q;
            for (int i = 1;i <= n;i ++){
                if (S >> (i - 1) & 1){
                    dis[i] = 0;
                    q.push(i);
                }else dis[i] = -1;
            }
            while (q.size()){
                int x = q.front();
                q.pop();
                for (auto y : G[x]){
                    if (dis[y] != -1)continue;
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
            ans = min(ans,*max_element(dis + 1,dis + n + 1));
        }
        printf("%d\n",ans);
        cleanup();
    }
    return 0;
}