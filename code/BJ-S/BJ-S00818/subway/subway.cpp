#include<bits/stdc++.h>
using namespace std;
int b[500010];
struct pai{
    int adr;
    long long w;
};
vector<pai>e[500010];
long long ma[510][510];
int main(){
    cin.tie(0),ios::sync_with_stdio(false);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(ma,0x3f,sizeof(ma));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            e[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<e[i].size();j++)
            for(int k=j+1;k<e[i].size();k++)
                ma[e[i][j].adr][e[i][k].adr]=min(ma[e[i][j].adr][e[i][k].adr],e[i][j].w+e[i][k].w);
    }
    for(int i=1;i<=n;i++){
        ma[i][i]=0;
        for(int j=1;j<=n;j++){
            ma[i][j]=min(ma[i][j],ma[j][i]);
            // cout<<ma[i][j]<<" ";
        }
        // cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n;x++){
            if(x==i)continue;
            for(int y=1;y<=n;y++){
                if(y==x||y==i)continue;
                ma[x][y]=min(ma[x][y],ma[x][i]+ma[i][y]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout<<ma[i][j]<<" ";
    //     cout<<"\n";
    // }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(int i=0;i<e[x].size();i++){
            for(int j=0;j<e[y].size();j++)
                ans=min(ans,e[x][i].w+ma[e[x][i].adr][e[y][j].adr]+e[y][j].w);
        }
        ans+=b[x]+b[y];
        cout<<ans<<"\n";
    }
    return 0;
}