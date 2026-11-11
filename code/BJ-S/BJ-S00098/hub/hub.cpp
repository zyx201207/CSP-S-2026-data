#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,k,ans;
int f[505][505];
vector<int> v[1000005];
bool vis[1000005],vis2[1000005];
void dfs2(int x){
    for(auto y:v[x]){
        if(!vis[y]){
            continue;
        }
        if(!vis2[y]){
            vis2[y] = 1;
            dfs2(y);
        }
    }
}
void dfs(int x){
    if(x==n+1){
        int cnt = 0,cnt2 = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                if(!vis2[i]){
                    cnt++;
                    vis2[i] = 1;
                    dfs2(i);
                }
                cnt2++;
            }
        }
        for(int i=1;i<=n;i++){
            vis2[i] = 0;
        }
        if(cnt<=2 && cnt2==k){
            int d = 0;
            for(int i=1;i<=n;i++){
                if(vis[i]){
                    continue;
                }
                int minn = 1e18;
                for(int j=1;j<=n;j++){
                    if(!vis[j]){
                        continue;
                    }
//                    if(t==0 && i==6 && vis[2] && vis[7] && vis[9]){
//                        cout << i << " " << j << " " << f[i][j] << endl;
//                    }
                    minn = min(minn,f[i][j]);
                }
                d = max(d,minn);
            }
//            if(d==1){
//                for(int i=1;i<=n;i++){
//                    if(vis[i]){
//                        cout << i << " ";
//                    }
//                }
//                cout << endl;
//            }
            ans = min(ans,d);
        }
        return;
    }
    vis[x] = 1;
    dfs(x+1);
    vis[x] = 0;
    dfs(x+1);
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            v[i].clear();
            for(int j=1;j<=n;j++){
                f[i][j] = 1e18;
            }
        }
        ans = 1e18;
        for(int i=1;i<n;i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
            f[x][y] = f[y][x] = 1;
        }
        for(int i=1;i<=n;i++){
            f[i][i] = 0;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
