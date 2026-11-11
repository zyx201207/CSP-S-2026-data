#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
const int MAXN=1505;
int g[MAXN][MAXN];
int c,n,m,d,q;
int w[MAXN];
int a[MAXN],t[MAXN];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    memset(g,-1,sizeof(g));
    cin >>c >>n >>m >>d >>q;
    for(int i=1;i<=m;i++) cin >>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin >>k;
        for(int j=1;j<=k;j++) cin >>a[j] >>t[j];
        for(int x=1;x<=k;x++){
            g[a[x]][a[x]]=0;
            for(int y=x+1;y<=k;y++){
                int sta1=a[x],sta2=a[y];
                //cout <<sta1 <<' ' <<sta2 <<endl;
                if(g[sta1][sta2]==-1) g[sta1][sta2]=g[sta2][sta1]=t[x]+t[y];
                else g[sta1][sta2]=g[sta2][sta1]=min(g[sta1][sta2],t[x]+t[y]);
            }
        }
    }
    //for(int i=1;i<=m;i++){for(int j=1;j<=m;j++) cout <<g[i][j] <<' ';cout <<endl;}
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==-1) g[i][j]=inf;
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin >>u >>v;
        cout <<g[u][v]+w[u]+w[v] <<endl;
    }
    return 0;
}
