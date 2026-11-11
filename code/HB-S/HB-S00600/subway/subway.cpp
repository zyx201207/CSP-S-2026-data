#include<bits/stdc++.h>
using namespace std;
constexpr int X=5e5+5, Y=505, Z=22;

int C,N,M,D,Q;
long long W[X];
int K[Y],cur[Y],a[X];
long long t[X];
long long G[Y][Y];
vector<pair<int,long long>> E[X];

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    double c=clock();

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>C>>N>>M>>D>>Q;
    for(int i=1;i<=M;i++) cin>>W[i];

    cur[1]=1;
    for(int i=1;i<=N;i++){
        cin>>K[i];
        for(int j=cur[i];j<=cur[i]+K[i]-1;j++){
            cin>>a[j]>>t[j];
            E[a[j]].emplace_back(i,t[j]);
        }
        cur[i+1]=cur[i]+K[i];
    }

    memset(G,0x3f,sizeof G);

    for(int i=1;i<=N;i++) G[i][i]=0;

    for(int i=1;i<=M;i++){
        int SZ=E[i].size();
        for(int j=0;j<SZ;j++){
            for(int k=j+1;k<SZ;k++){
                int u=E[i][j].first, v=E[i][k].first;
                long long w=E[i][j].second+E[i][k].second;
                G[u][v]=G[v][u]=min(G[u][v],w);
            }
        }
    }

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }

    while(Q--){
        int S,T; cin>>S>>T;
        long long res=0x3f3f3f3f3f3f3f3f;
        for(auto p:E[S]){
            int u=p.first; long long w1=p.second;
            for(auto q:E[T]){
                int v=q.first; long long w2=q.second;
                res=min(res,w1+w2+G[u][v]);
            }
        }
        cout<<res+W[S]+W[T]<<'\n';
    }
}