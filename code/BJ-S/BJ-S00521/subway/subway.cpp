#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int M=500005,N=505;
int n,m,q,w[M];
LL dis[N][N],ans;
vector<pair<int,int> > mm2[M];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        for(int j=1;j<=x;j++){
            int y,z;cin>>y>>z;
            mm2[y].push_back({i,z});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        for(int j=0;j<mm2[i].size()-1;j++){
            LL jv=mm2[i][j].first,jw=mm2[i][j].second;
            for(int k=j+1;k<mm2[i].size();k++){
                LL kv=mm2[i][k].first,kw=mm2[i][k].second;
                dis[jv][kv]=min(dis[jv][kv],jw+kw);
                dis[kv][jv]=min(dis[kv][jv],jw+kw);
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(k==i || k==j || i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<mm2[x].size();i++){
            LL iv=mm2[x][i].first,iw=mm2[x][i].second;
            for(int j=0;j<mm2[y].size();j++){
                LL jv=mm2[y][j].first,jw=mm2[y][j].second;
                ans=min(ans,dis[iv][jv]+iw+jw);
            }
        }
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
