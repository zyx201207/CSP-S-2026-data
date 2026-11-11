#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=5e2+5;
int c,n,m,d,q,w[M],k,a,cnt,x,y;
long long t[M];
long long sum[N],ans;
struct node{
    int line,id;
};
vector<node>sub[M];//the subways that connect with the stop
long long dis[N][N];//distance
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        sum[i]=sum[i-1]+k;
        for(int j=1;j<=k;j++){
            cin>>a>>t[++cnt];
            for(int l=0;l<sub[a].size();l++){
                dis[sub[a][l].line][i]=dis[i][sub[a][l].line]=t[cnt]+t[sum[sub[a][l].line-1]+sub[a][l].id];
            }
            sub[a].push_back({i,j});
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    floyd();
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=0x3f3f3f3f3f3f3f3f;
        for(auto u:sub[x]){
            for(auto v:sub[y]){
                ans=min(ans,dis[u.line][v.line]+t[sum[u.line-1]+u.id]+t[sum[v.line-1]+v.id]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
