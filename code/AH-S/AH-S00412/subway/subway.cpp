#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,d,q,c;
vector<int>R[600050];
vector<long long>RT[600050];
long long w[600050];
long long G[600][600];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
       // cin>>w[i];
    }
   // cerr<<m<<endl;
    for(int i=1;i<=n;i++){
        int len;
        scanf("%d",&len);
        for(int j=1;j<=len;j++){
            int v;long long t;
            scanf("%d",&v);
          //  K[i].push_back(v);
            scanf("%lld",&t);
          //  T[i].push_back(t);
            //cin>>v>>t;
            R[v].push_back(i);
            RT[v].push_back(t);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)G[i][j]=
            0x3f3f3f3f3f3f3f3fll;
            G[i][i]=0;
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<R[i].size();j++){
            for(int k=j+1;k<R[i].size();k++){
                int v=R[i][k];
                int u=R[i][j];
                long long w=RT[i][k]+RT[i][j];
                G[u][v]=G[v][u]=
                min(G[u][v],w);
                cnt++;
            }
        }
    }
    //cerr<<cnt<<endl;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=min(G[i][k]+G[k][j],G[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
     //  cin>>x>>y;
        long long mn=0x3f3f3f3f3f3f3f3fll;
        for(int j=0;j<R[x].size();j++){
            for(int k=0;k<R[y].size();k++){
                int v=R[y][k];
                int u=R[x][j];
                long long w=RT[y][k]+RT[x][j];
                mn=min(mn,w+G[u][v]);
            }
        }
        printf("%lld\n",mn+w[x]+w[y]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
