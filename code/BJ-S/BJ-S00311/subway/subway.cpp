#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=510,maxn=5e5+10;
int n,m,C,d,q,w[maxn],dis[maxm][maxm],k[maxm];
vector<pair<int,int>>sub[maxm];
vector<pair<int,int>>bel[maxn];

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        sub[i].reserve(k[i]+2);
        for(int j=1;j<=k[i];j++){
            cin>>sub[i][j].first>>sub[i][j].second;
            bel[sub[i][j].first].push_back({i,j});
        }
    }
    /*for(int i=1;i<=m;i++){
        cout<<"bel[";
        cout<<i;
        cout<<"]: ";
        for(auto v:bel[i])cout<<v.first<<" ";cout<<'\n';
    }*/memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=m;k++){
        int siz=bel[k].size();
        for(int i=0;i<siz;i++){
            for(int j=i+1;j<siz;j++){//cout<<"***";
                dis[bel[k][i].first][bel[k][j].first]=dis[bel[k][j].first][bel[k][i].first]=
                min(dis[i][j],sub[bel[k][i].first][bel[k][i].second].second+sub[bel[k][j].first][bel[k][j].second].second);
            }
        }
    }/*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<'\n';
    }*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
            }
        }
    }/*cout<<"\n\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    while(q--){
        int x,y;cin>>x>>y;int ans=w[x]+w[y],anss=1ll<<60;
        int sizx=bel[x].size(),sizy=bel[y].size();
        for(int i=0;i<sizx;i++){
            for(int j=0;j<sizy;j++){
                anss=min(anss,dis[bel[x][i].first][bel[y][j].first]+
                sub[bel[x][i].first][bel[x][i].second].second+sub[bel[y][j].first][bel[y][j].second].second);
            }
        }
        cout<<ans+anss<<'\n';
    }
    return 0;
}
