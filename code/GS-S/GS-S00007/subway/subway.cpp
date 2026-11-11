#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q;
int w[500005];
int way[505][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d", &c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i++) scanf("%d",&w[i]);
    for(int i = 1,k;i <= n;i++){
        scanf("%d",&k);
        for(int j = 1,x;j <= k;j++){
            scanf("%d",&x);
            scanf("%d",&way[i][x]);
        }
    }
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        ll ans = w[x] + w[y];

        printf("%lld\n",ans);
    }
    return 0;
}
