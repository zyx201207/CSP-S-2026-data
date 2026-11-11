#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[20005],a[505][20005],t[505][20005],xi[505],x,y;//m<=5*10^5
long long ppy[500][500][2],g1=0,g2=0,gg;
void aa(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ppy[i][j][0]=4e9;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=xi[i];j++){
            g1=a[i][j];
           for(int k=1;k<=xi[i];k++){
                if(j==k)continue;
               g2=a[i][k];
                ppy[g1][g2][0]=t[i][g1]+t[i][g2];
                ppy[g2][g1][0]=t[i][g1]+t[i][g2];
                ppy[g1][g2][1]=i;
                ppy[g2][g1][1]=i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(k==i||k==j||!ppy[j][k][0]||!ppy[i][k][0])continue;
                gg=ppy[i][k][0]+ppy[k][j][0]+t[ppy[i][k][1]][k]+t[ppy[k][j][1]][k];
                if(gg<ppy[i][j][0]){
                    ppy[i][j][0]=min(gg,ppy[i][j][0]);
                    ppy[j][i][0]=min(gg,ppy[j][i][0]);
                    ppy[i][j][1]=ppy[k][j][1];
                    ppy[j][i][1]=ppy[k][i][1];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<ppy[x][y][0]+w[x]+w[y]<<endl;
    }
    return;
}
void b(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ppy[i][j][0]=5e11+2e9;
        }
    }
    for(int i=1;i<=n;i++){
        g1=a[i][1],g2=a[i][2];
        ppy[g1][g2][0]=t[i][g1]+t[i][g2];
        ppy[g2][g1][0]=t[i][g1]+t[i][g2];
        ppy[g1][g2][1]=i;
        ppy[g2][g1][1]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=1;k<=m;k++){
                if(k==i||k==j||!ppy[j][k][0]||!ppy[i][k][0])continue;
                gg=ppy[i][k][0]+ppy[k][j][0]+t[ppy[i][k][1]][k]+t[ppy[k][j][1]][k];
                if(gg<ppy[i][j][0]){
                    ppy[i][j][0]=min(gg,ppy[i][j][0]);
                    ppy[j][i][0]=min(gg,ppy[j][i][0]);
                    ppy[i][j][1]=ppy[k][j][1];
                    ppy[j][i][1]=ppy[k][i][1];
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<ppy[x][y][0]+w[x]+w[y]<<endl;
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld\n",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld ",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld ",&xi[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld %lld",&a[i][j],&t[i][j]);
        }
    }
    if(c>=1&&c<=3){
       aa();
    }
    else if(c>=7&&c<=11){
        b();
    }
    return 0;
}
