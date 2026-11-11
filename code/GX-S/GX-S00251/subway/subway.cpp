#include<bits/stdc++.h>
using namespace std;
const int MAXn = 510 , MAXm = 5e5+10 , MAXq = 1e5+10;
int c,n,m,d,q;
int w[MAXm],k[MAXm],a[MAXn][MAXm],t[MAXn][MAXm],x[MAXq],y[MAXq];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1 ; i <= m ; i++) scanf("%d",&w[i]);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d",k[i]);
        for(int j = 1 ; j <= k[i] ; j++) scanf("%d %d",&a[i][j],&t[i][j]);
    }
    for(int i = 1 ; i <= q ; i++) scanf("%d %d",&x[i],y[i]);
    while(1){system("gunmu.cpp");}
    return 0;
}
