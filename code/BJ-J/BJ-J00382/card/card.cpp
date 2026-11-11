#include<bits/stdc++.h>
using namespace std;
const int N = 500001, M = 300001;
int n, m, a[N], lst[M], nxt[N][20], ans[M];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        nxt[lst[a[i]]][0] = i;
        lst[a[i]] = i;
    }
    nxt[0][0] = 0;
    for(int j = 1; j < 20; j++){
        for(int i = 1; i <= n; i++){
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            //if(j<5)printf("%d ", nxt[i][j - 1]);
        }
        //printf("\n");
    }
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j <= n){
            //尽量跳
            for(int k = 19; k >= 0; k--){
                if(nxt[j][k])j=nxt[j][k];
            }
            //跳完了后走
            ans[a[j]]++;
            j++;
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d ", ans[i]);
    }
}
