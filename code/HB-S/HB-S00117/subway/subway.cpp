#include<bits/stdc++.h>
using namespace std;

const int MAXM=5e5+10, MAXN=510;
const long long INF=1e9+20;

struct p{
    int line;
    long long t;
};

int c,n,m,d,q;
long long w[MAXM], dis[25][25]={INF};
d p[MAXM][25];
int syb[MAXN];
bool op[MAXN][MAXM];
long long mind[25][25]=INF*INF;

int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
    for(int i=1;i<=25;i++) dis[i][i]=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    };
    for(int i=1;i<=n;i++){
        int k,a,t;
        cin>>k;
        for(int j=1;j<=k;i++){
            cin>>a>>t;
            p[a][++syb[a]].line=i;
            p[a][++syb[b]].t=t;
            op[i][a]=true;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=syb[i];j++){
            for(int k=j+1;k<=syb[i];k++){
                dis[p[i][j].line][p[i][k].line]=min{ dis[p[i][j].line][p[i][k].line],p[i][j].t+p[i][k].t};
                dis[p[i][k].line][p[i][j].line]=min{ dis[p[i][k].line][p[i][j].line],p[i][j].t+p[i][k].t};
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                mind[i][j]=min{mind[i][j],mind[i][k]+dis[j][k]};
            }
        }
    }
    for(int i=1;i<=q;i++){
        int r;
        cin>>r;

    }
}
