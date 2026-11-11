#include<bits/stdc++.h>
using namespace std;
#define Pii pair<long long,int>

const int N=505,M=5e5+5;
int c,n,m,d,q,x,y,k,a,t,w[M],backmap[M][25][2],topp[M],mapp[N][N];
long long dis[N][N],ans;
priority_queue<Pii,vector<Pii>,greater<Pii>> pq;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            backmap[a][topp[a]][0]=i;
            backmap[a][topp[a]++][1]=t;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            mapp[i][j]=INT_MAX;
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<topp[i];j++){
            for(int k = j+1;k<topp[i];k++){
                int u = backmap[i][j][0],w = backmap[i][k][0],v = backmap[i][j][1]+backmap[i][k][1];
                mapp[u][w]=min(mapp[u][w],v);
                mapp[w][u]=min(mapp[w][u],v);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j]=LONG_MAX;
        }
        dis[i][i]=0;
        pq.push({0,i});
        while(!pq.empty()){
            int now=pq.top().second;
            long long val=pq.top().first;
            pq.pop();
            if(val>dis[i][now]) continue;
            for(int j = 1;j<=n;j++){
                if(mapp[now][j]!=INT_MAX && dis[i][j]>dis[i][now]+mapp[now][j]){
                    dis[i][j]=dis[i][now]+mapp[now][j];
                    pq.push({dis[i][j],j});
                }
            }
        }
    }
    while(q--){
        ans=LONG_MAX;
        cin>>x>>y;
        for(int i = 0;i<topp[x];i++){
            for(int j = 0;j<topp[y];j++){
                int pointx = backmap[x][i][0],pointy=backmap[y][j][0];
                if(dis[pointx][pointy]!=LONG_MAX) ans=min(ans,dis[pointx][pointy]+backmap[x][i][1]+backmap[y][j][1]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }

    return 0;
}
