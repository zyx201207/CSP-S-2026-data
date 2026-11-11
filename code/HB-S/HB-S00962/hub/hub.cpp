#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6+7;
int c, t;

int fa[MAXN], depth[MAXN], maxd;
struct node{
    vector<int> childs;
}G[MAXN];

int main(){
    scanf("%d%d", &c, &t);
    while(t--) {
        int n, k, cnt = 0;
        scanf("%d%d", &n, &k);
        for(int i = 0; i<n; i++){
            int u, v;
            scanf("%d", &u, &v);
            G[u].childs.push_back(v);
            fa[v] = u;
            depth[v] = depth[u]+1;
            maxd = max(depth[v], maxd);
        }
        
    }
}