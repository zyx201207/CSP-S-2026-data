#include <bits/stdc++.h>
using namespace std;
const int N = 505,M = 5 * 1e5 + 5;
struct subway{
    int line[25];//他是几号线的
    int cnt;//经过此站的线路数
    int w;//站厅到地铁口时间
    int time[25];//该站厅到各线路站台的时间
}s[M];
int c,n,m,d,q,x,y;
int k[N][M];
int num[N],mn = INT_MAX;
bool vis[M];
void dfs(int time,int now,int line){//time:当前用时 now:当前位置 line:当前是第几号线
    if(vis[now] && now != x)return;
    if(now == y){
        mn = min(mn,time + s[y].time[line] + s[y].w);
        return;
    }
    for(int i = 1;i <= s[now].cnt;i++){
        for(int j = 1;j <= num[i];j++){
            vis[k[s[now].line[i]][j]] = true;
            if(i == line){
                dfs(time,k[s[now].line[i]][j],line);
            }else{
                dfs(time + s[now].time[line] + s[now].time[i],k[s[now].line[i]][j],s[now].line[i]);
            }
            vis[k[s[now].line[i]][j]] = false;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> s[i].w;
    }
    for(int i = 1;i <= n;i++){
        cin >> num[i];
        for(int j = 1;j <= num[i];j++){
            int a,t;
            cin >> a >> t;
            k[i][j] = a;
            s[a].cnt++;
            s[a].line[s[a].cnt] = i;
            s[a].time[i] = t;
        }
    }
    while(q--){
        mn = INT_MAX;
        memset(vis,false,sizeof(vis));
        cin >> x >> y;
        vis[x] = true;
        for(int i = 1;i <= s[x].cnt;i++){
            for(int j = 1;j <= num[i];j++){
                vis[k[s[x].line[i]][j]] = true;
                dfs(s[x].w + s[x].time[i],k[s[x].line[i]][j],s[x].line[i]);
                vis[k[s[x].line[i]][j]] = false;
            }
        }
        cout << mn << '\n';
    }
    return 0;
}
