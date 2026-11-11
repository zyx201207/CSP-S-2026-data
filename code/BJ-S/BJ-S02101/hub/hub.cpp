#include <bits/stdc++.h>
using namespace std;
// #define int long long

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

const int N = 1e6 + 10;
const int K = 22;

int c,t,n,k,dep[N],st[K][N],ye[N],root,vis[N],vis1[N],vis2[N],len[N],ma,sum,ans;
vector<int> v[N];

void dfs2(int u,int f){
    dep[u] = 0;
    st[0][u] = f;
    if(v[u].size() == 1 && f != 0){
        ye[u] = 1;
    }else{
        ye[u] = 0;
    }
    for(int i = 0;i < v[u].size();i++){
        if(v[u][i] != f){
            dfs2(v[u][i],u);
            dep[u] = max(dep[u],dep[v[u][i]] + 1);
        }
    }
}

void dfs3(int u,int fa){
    len[u] = 0;
    for(int i = 0;i < v[u].size();i++){
        if(v[u][i] != fa && vis[v[u][i]]){
            dfs3(v[u][i],u);
            if(u == root && !vis2[u]){
                if(vis1[v[u][i]]){
                    ma = max(ma,len[u] + 1);
                    len[u] = max(len[u],1);
                    // cout << u << " " << v[u][i] << " " << ma << endl;
                }else{
                    ma = max(ma,len[u] + len[v[u][i]] + 1);
                    len[u] = max(len[u],len[v[u][i]] + 1);
                    // cout << u << " " << v[u][i] << " " << ma << endl;
                }
            }else{
                if(vis1[v[u][i]]){
                    ma = max(ma,1);
                    len[u] = max(len[u],1);
                }else{
                    ma = max(ma,len[v[u][i]] + 1);
                    len[u] = max(len[u],len[v[u][i]] + 1);
                }
            }
        }
    }
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    
    c = read(),t = read();

    while(t--){
        n = read(),k = read();
        for(int i = 1;i <= n;i++){
            v[i].clear();
        }
        for(int i = 1;i <= n - 1;i++){
            int x = read(),y = read();
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = 2e18;
        // root = 3;
        for(root = 1;root <= n;root++){
            dfs2(root,0);
            for(int i = 1;i < K;i++){
                for(int j = 1;j <= n;j++){
                    st[i][j] = st[i - 1][st[i - 1][j]];
                }
            }
            int l = 0,r = dep[root];
            while(l < r){
                int mid = (l + r) >> 1;
                for(int i = 1;i <= n;i++) vis[i] = vis1[i] = vis2[i] = 0;
                sum = ma = 0;
                for(int i = 1;i <= n;i++){
                    if(ye[i]){
                        int f = i;
                        for(int j = K - 1;j >= 0;j--){
                            if(mid & (1 << j)){
                                f = st[j][f];
                            }
                        }
                        vis1[f] = vis2[f] = 1;
                        for(;f;f = st[0][f]){
                            if(vis[f]){
                                vis1[f] = 1;
                                break;
                            }else{
                                vis[f] = 1;
                                sum++;
                            }
                        }
                    }
                }
                dfs3(root,0);
                // cout << mid << ": " << sum << " " << ma << endl;
                // for(int i = 1;i <= n;i++){
                //     cout << vis[i] << " ";
                // }
                // cout << endl;
                // for(int i = 1;i <= n;i++){
                //     cout << len[i] << " ";
                // }
                // cout << endl;
                sum -= min(ma - 1,2 * mid);
                if(sum <= k){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            // cout << root << ": " << l << endl;
            ans = min(ans,l);
        }
        cout << ans << endl;
    }

    return 0;
}