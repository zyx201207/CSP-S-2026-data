#include<bits/stdc++.h>
using namespace std;

const int M = 5e5 + 5,N = 505;

int c,n,m,d,q;

bool vis[M];
int w[M];       //表示地铁口到站厅所用时间
int a[N][M];    //表示第i条路线途径的站点
int t[N][M];    //表示第i条路线到第j个车站站厅所用时间
int k[N];       //表示第i条路线途径多少个车站
int ans = INT_MAX;

void dfs(int cur,int en,int time,int line){
    vis[cur] = 1;
    time+=t[line][cur];
    if(cur == en){
        time+=w[cur];
        ans = min(ans,time);
        return ;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k[i];j++){
            if(a[i][j] == cur){
                for(int h = 1;h<=k[i];h++){
                    if(vis[a[i][h]] == 1 || h == j){
                        continue;
                    }
                    dfs(a[i][h],en,time+t[i][cur],i);
                }

            }
        }
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
        cin >> w[i];
    }
    for(int i = 1;i<=n;i++){
        cin >> k[i];
        for(int j = 1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        int x,y;
        cin >> x >> y;
        dfs(x,y,w[x],0);
        cout << ans << endl;
    }
    return 0;
}
