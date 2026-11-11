#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[1005];
vector<int>vec[1005];
int cnt = 0;
int dep[1005];
void check(int x,int fa){
    dep[x] = dep[fa] + 1;
    if(!vis[fa] && vis[x]){cnt++;}
    for(int i : vec[x]){
        if(i == fa){
            continue;
        }
        check(i,x);
    }
}
int maxa[1005];
void check2(int x,int fa){
    if(fa != 0) maxa[x] = min(maxa[x],maxa[fa] + 1);
    for(int i : vec[x]){
        if(i == fa){
            continue;
        }
        check2(i,x);
    }
}
int ans = 1e8;
void dfs(int x,int u){
    if(u > k){
        return ;
    }
    if(x > n){
        cnt = 0;
        check(1,0);
        if(cnt != 2){
            return;
        }
        for(int i = 1;i <= n;i++){
            maxa[i] = 1e9;
        }
        for(int i = 1;i <= n;i++){
            if(vis[i] == 1){
                maxa[i] = 0;
                check2(i,0);
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            cnt = max(cnt,maxa[i]);
        }
        ans = min(ans,cnt);
        return;
    }
    vis[x] = 1;
    dfs(x + 1,u + 1);
    vis[x] = 0;
    dfs(x + 1,u);

}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans = 1e8;
        for(int i = 1;i <= n;i++){
            vec[i].clear();
            dep[i] = 0;
        }
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int x,y;
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        dfs(1,0);
        cout << ans << "\n";
    }

    return 0;
}
