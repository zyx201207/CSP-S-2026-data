#include<bits/stdc++.h>

using namespace std;

int c,m,n,d,q;
int w[25];
int a[30][30][5];
int l[500011][2];
int x,y;
int ans = 1000000010;


inline void dfs(int x,int y,int z){
    if(x == y)
        ans = min(ans,z);
    for(int i = 1; i <= m; i++){
        if(a[x][i][0] == 1){
            dfs(i,y,z + a[x][i][1]);
        }
    }

}

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1; i <= m; i++) {
        scanf("%d",&w[i]);
    }
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d",&k);
        for(int j = 1; j <= k; j++){
            scanf("%d%d",&l[j][0],&l[j][1]);
        }
        for(int j = 2; j <= k; j++){
            a[l[j - 1][0]][l[j][0]][0] = 1;
            a[l[j - 1][0]][l[j][0]][1] = l[j][1] + l[j - 1][1];
        }
    }
    for(int r = 1; r <= q; r++){
        scanf("%d%d",&x,&y);
        dfs(x,y,w[x] + w[y]);
        printf("%d\n",ans);
    }
    return 0;
}
