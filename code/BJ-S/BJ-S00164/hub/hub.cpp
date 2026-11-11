#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define inf 0x3f3f3f3f
vector<int> edg[maxn];
int c,t,n,k;
int s[maxn];
void make(int x){
    s[x] = x;
}
int find(int x){
    if(s[x] == x){
        return s[x];
    }
    return s[x] = find(s[x]);
}
void merge(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    s[x] = y;
}
vector<int> vec;
queue<int> q;
int ans;
bool vis[maxn];
int dis[maxn];
void dfs(int fa,int u){
    //cout << u << endl;
    for(int i = 0;i < edg[u].size();i++){
        int v = edg[u][i];
        if(v == fa){
            continue;
        }
        if(vis[u] && vis[v]){
            merge(u,v);
        }
        dfs(u,v);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans = inf;
        cin >> n >> k;
        for(int i = 1;i <= n;i++){
            edg[i].clear();
        }
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        for(int i = 1;i < (1 << n);i++){
            int res = 0,cnt = 0;
            if(__builtin_popcount(i) != k){
                continue;
            }
            for(int i = 1;i <= n;i++){
                make(i);
                vis[i] = false;
            }
            vec.clear();
            while(!q.empty()){
                q.pop();
            }
            for(int j = 1;j <= n;j++){
                if((i >> (j - 1)) & 1){
                    vec.push_back(j);
                    vis[j] = true;
                }
            }
            dfs(0,1);
            int val1 = 0,val2 = 0;
            bool flag = true;
            for(auto x : vec){
                s[x] = find(s[x]);
                //cout << x <<" " << s[x] << endl;
                if(!val1){
                    val1 = s[x];
                }
                else if(s[x] != val1 && !val2){
                    val2 = s[x];
                }
                if(val1 && s[x] != val1 && val2 && s[x] != val2){
                    flag = false;
                    //cout << s[x] << " " << val1 << " " << val2 << endl;
                }
            }
            if(!flag){
                continue;
            }
            //cout << 666 << endl;
            for(int i = 1;i <= n;i++){
                dis[i] = inf;
            }
            for(auto x : vec){
                    //cout << 666 << endl;
                    vis[x] = false;
                dis[x] = 0;
                q.push(x);
                cnt++;
            }
            //cout << q.size() << endl;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(vis[u]){
                    continue;
                }
                vis[u] = true;
                if(cnt >= k * k){
                    break;
                }
                for(int i = 0;i <= edg[u].size();i++){
                    int v = edg[u][i];
                    dis[v] = dis[u] + 1;
                    res = max(res,dis[v]);
                    q.push(v);
                    cnt++;
                }
            }
            //cout << res << endl;
            ans = min(ans,res);
        }
        cout << ans << endl;
    }
    return 0;
}
