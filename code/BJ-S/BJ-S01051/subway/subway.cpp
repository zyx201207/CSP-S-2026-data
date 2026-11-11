#include <bits/stdc++.h>
#define int long long
using namespace std;
//w代表地铁站到站厅距离，k就是题目中每一个路线经过的地铁站数量，g代表桶（存储每一个地铁站各个路线站厅到地铁站的距离，first是第几条线，second是时间），dis就是floyd的dis
int w[500010],k[510],dis[510][510];
vector<pair<int,int> > g[500010];
vector<int> t[500010];
bool cmp(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first) return x.second<y.second;
    return x.first<y.first;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            g[x].push_back({i,y});
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<"g["<<i<<"]["<<j<<"]= "<<g[i][j].first<<" "<<g[i][j].second<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size();j++){
            //cout<<g[i][j].first<<" "<<g[i][j].second<<" ";
            for(int k=0;k<g[i].size();k++){
                if(k==j) continue;
                //cout<<"!"<<g[i][k].first<<" "<<g[i][j].first<<" "<<g[i][j].second<<" "<<g[i][k].second<<"\n";
                dis[g[i][k].first][g[i][j].first]=g[i][j].second+g[i][k].second;
            }
        }
        //cout<<"\n";
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
                //cout<<dis[i][j]<<" ";
            }
            //cout<<endl;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y,ans=1e18;
        cin>>x>>y;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                //cout<<i<<" "<<j<<" "<<g[x][i].first<<" "<<g[y][j].first<<" "<<dis[g[x][i].first][g[y][j].first]<<" "<<g[x][i].second<<" "<<g[y][i].second<<endl;
                ans=min(ans,dis[g[x][i].first][g[y][j].first]+g[x][i].second+g[y][j].second);
             }
        }
        //cout<<w[x]<<" "<<w[y]<<"\n";
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
//g++ -Wall -o t2 t2.cpp -O2 -std=c++14 -static
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/