#include <bits/stdc++.h>
using namespace std;
int C,T;
const int MMax = 2e6+9;
int dep[MMax];
int dep2[MMax];
int vis[MMax];
vector<int> S[MMax];
void dfs_n(int x,int k){
    dep[x] = k;
    vis[x] =1;
    for(int i:S[x]){
        if(vis[i]==0)dfs_n(i,k+1);
    }
    return;
}
void dfs2(int x,int k){
    dep2[x] = k;
    vis[x] = 1;
    for(int i:S[x]){
        if(vis[i]==0)dfs2(i,k+1);
    }
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> T;
    while(T--){
        int N ,K;
        cin >> N >> K;
        for(int i=1;i<=N-1;i++){
            int u,v;
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        memset(dep,0x3f,sizeof(dep));
        memset(vis,0,sizeof(vis));
        dfs_n(1,0);
        int ans = 0,anszong = 0x3f;
        for(int i=2;i<=N;i++){
            memset(dep2,0x3f,sizeof(dep2));
            memset(vis,0,sizeof(vis));
            dfs2(i,0);
            for(int j=1;j<=N;j++)cout << dep2[j] << " ";
            cout <<'\n';
            ans = 0;
            for(int j=1;j<=N;j++){
                ans = max(min(dep[j],dep2[j]),ans);
            }
            anszong = min(ans ,anszong);

        }
        cout << anszong << '\n';
    }
    return 0;
}
