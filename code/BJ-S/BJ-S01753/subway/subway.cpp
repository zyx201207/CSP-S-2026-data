#include<bits/stdc++.h>
using namespace std;
const int G=100000000;
int c,n,m,d,q,ans[1005][1005],a[1005][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=0;i<=1002;i++){
        for(int j=0;j<=502;j++){
            a[i][j]=G;
        }
        for(int j=0;j<=1002;j++){
            ans[i][j]=G;
        }
    }
    for(int i=1;i<=m;i++) scanf("%d",&a[i][0]);
    for(int i=1;i<=n;i++){
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][i]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            ans[i][j]=a[i][i]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            ans[i][j]=min(ans[i][j],ans[i-1][j]+ans[i][j-1]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d",min(ans[x][y],ans[y][x])+a[x][0]+a[y][0]);
    }
    return 0;
}
