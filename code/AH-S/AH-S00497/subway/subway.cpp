#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
const int M = 600;
const int INF = 1e18;
typedef struct Node{
    int loc;
    int x;
}Node;
int c,n,m,d,q;
int w[N];
vector<int> a[M];
vector<int> t[M];
map<pair<int,int>,bool> mp;
int vis[N];
int res = INF;
int read(){
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(!isdigit(ch)){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(isdigit(ch)){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*f;
}
int dfs(int u,int l,int ans,int e){
    if(u == e){
        return 0;
    }
    for(int i = 1;i<=m;i++){
        if(i == u) continue;
        if(vis[i] == true) continue;
        Node node,nodes;
        node.x = i;
        nodes.x = u;
        for(int j = 1;j<=n;j++){
            node.loc = nodes.loc = j;
            if(mp[{j,i}] != true) continue;
            if(mp[{j,u}] != true) continue;
            ans += t[j][node.loc];
            if(l != j){
                ans += t[j][nodes.loc];
            }
            vis[i] = true;
            dfs(i,j,ans,e);
            vis[i] = false;
            dfs(i,j,ans,e);
        }
    }
    res = min(res,ans);
    return res;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c = read();
    n = read();
    m = read();
    d = read();
    q = read();
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        int k;
        k = read();
        for(int j = 1;j<=k;j++){
            int x,y;
            x = read();
            y = read();
            Node node;
            node.loc = j;
            node.x = x;
            mp[{j,x}] = true;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    while(q--){
        res = INF;
        memset(vis,false,sizeof(vis));
        int x,y;
        x = read();
        y = read();
        cout<<dfs(x,0,0,y)+w[x]+w[y]<<'\n';
    }
    return 0;
}