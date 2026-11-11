#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=5e2+10;
const int maxm=5e5+10;
const int inf=INT_MAX;
vector<int> station[maxn],line[maxm],e[maxn];
int c,n,m,d,q,ans=inf,w[maxm],k[maxn],a[maxn][maxm],t[maxn][maxm],dis[maxn][maxn],zai[maxm][maxn],dist[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for (int i=0;i<maxm;i++) dist[i]=inf;
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++){
        cin>>k[i];
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];{
            line[a[i][j]].push_back(i);
            station[i].push_back(a[i][j]);
            zai[int(a[i][j])][i]=j;
        }
    }
    for (int i=1;i<=m;i++)
        if (line[i].size()>=2)
            for (int j=0;j<line[i].size();j++)
                for (int mask=j+1;mask<line[i].size();mask++){
                    dis[i][j]=inf;
                    int x=zai[int(i)][int(line[i][j])],y=zai[int(i)][int(line[i][mask])];
                    dis[i][j]=dis[j][i]=min(dis[i][j],t[line[i][j]][x]+t[line[i][mask]][y]);
                }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (dis[i][j]!=inf){
                e[i].push_back(j);
                e[j].push_back(i);
            }
    while (q--){
        int st,ed;cin>>st,ed;queue<int> que;
        for (int i=0;i<line[st].size();i++){
            que.push(line[st][i]);
            dist[u]=t[st][line[st][i];
        }
        while (que.size()){
            int u=que.front();que.pop();
            for (int i=0;i<e[u].size();i++){
                int v=e[u][i];
                if (dist[v]==inf){
                    dist[v]=dist[u]+dis[u][v];
                    que.push(v);
                }
            }
        }
        for (int i=0;i<line[ed].size();i++)
            ans=min(ans,dist[line[ed][i]]+w[st]+w[ed]+t[line[ed][i]][ed]);
    }
    cout << ans << '\n';
    return 0;
}
//zai[int(line[i][j])][i]
