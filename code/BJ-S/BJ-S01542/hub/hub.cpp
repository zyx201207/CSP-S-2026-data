#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> tu[N];
int s[N];
int mx[N];
int t[N];
int fa[N][30];
void dfs(int u,int f){
    fa[u][0]=f;
    s[u]=s[f]+1;
    mx[u]=s[u];
    for(int i=0;i<tu[u].size();i++){
        int v=tu[u][i];
        if(v==f) continue;
        dfs(v,u);
        mx[u]=max(mx[u],mx[v]);
    }
}
int LCA(int u,int v){

}
bool check(int k){

}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C,T;
    cin >> C >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        for(int i=1;i<=n;i++) tu[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin >> u >> v;
            tu[u].push_back(v);
            tu[v].push_back(u);
        }
        dfs(1,0);
        cout << (mx[1]+1)/2 << "\n";
    }
    return 0;
}
