#include <bits/stdc++.h>
using namespace std;
int a[200005];
int vis[200005];
int n,m;
int maxn;

void dfs(int num,int x) {
    if(x == m) maxn = max(maxn,num);
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        vis[i] = 1;
        dfs(num & a[i],x+1);
        vis[i] = 0;
    }
    return;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++) {
        vis[i] = 1;
        dfs(a[i],1);
    }
    printf("%d",maxn);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

