#include<stdio.h>
int w[500]; // 每个地铁站的地铁口走到站厅需要的时间
int k;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &w[i]);
    }

    return 0;
}
