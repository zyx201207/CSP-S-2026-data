#include<bits/stdc++.h>
using namespace std;

long long w[1145140];
long long dis[514][514];
vector<pair<int,long long> > bian[1145140];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int a,t;
            cin>>a>>t;
            bian[a].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=LONG_LONG_MAX/10;
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        int len=bian[i].size();
        for(int j=0;j<len;j++)
            for(int k=0;k<len;k++)
                dis[bian[i][j].first][bian[i][k].first]=min(dis[bian[i][j].first][bian[i][k].first],bian[i][j].second+bian[i][k].second);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=LONG_LONG_MAX/10;
        for(auto v1:bian[x])
            for(auto v2:bian[y])
                ans=min(ans,v1.second+v2.second+dis[v1.first][v2.first]);
        cout<<ans+w[x]+w[y]<<'\n';
    }
}

//这年头流行不给最大点的大洋里了？