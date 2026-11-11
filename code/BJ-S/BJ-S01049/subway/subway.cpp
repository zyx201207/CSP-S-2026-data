#include<iostream>
#include<vector>
using namespace std;
const int maxn=510,maxm=505000;
int c,n,m,d,q;long long w[maxm],ans;
int k,a,t;long long dis[maxn][maxn];
struct tt{
    int num;long long d;
};
vector<tt>v[maxm];
int x,y;
inline void f(int uu,int vv,long long uv){
    dis[uu][vv]=min(dis[uu][vv],uv),dis[vv][uu]=dis[uu][vv];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=100000000000000000;
    for(int i=1;i<=m;i++){
        int xx=v[i].size();
        for(int j=0;j<xx;j++)for(int l=j+1;l<xx;l++)f(v[i][j].num,v[i][l].num,v[i][j].d+v[i][l].d);
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        cin>>x>>y;ans=100000000000000000;
        for(int i=0;i<v[x].size();i++)for(int j=0;j<v[y].size();j++)ans=min(ans,v[x][i].d+v[y][j].d+dis[v[x][i].num][v[y][j].num]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}