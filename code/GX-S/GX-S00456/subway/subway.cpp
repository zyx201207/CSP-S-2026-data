#include<bits/stdc++.h>
#define MAXN 503
#define MAXM 500006
using namespace std;

struct road{
    int roadn;//经过的地铁站数
    vector<int> a;//经过的地铁站
    vector<int> roadt;//线路的走到站台i需要的时间
};
struct edge{
    int to,val;
};

int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,出行计划数。
int w[MAXM];//从每个地铁站的地铁口走到站厅需要的时间
road r[MAXN];//线路信息
vector<edge> map_[MAXM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>r[i].roadn;
        for(int j=1;j<=r[i].roadn;j++){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            r[i].a.push_back(tmp1);
            r[i].roadt.push_back(tmp2);
        };
    }


    //build map
    for(int i=1;i<=n;i++){
        for(int j=0;j<r[i].roadn-1;j++){
            int ROADU=r[i].a[j],ROADV=r[i].a[j+1],BianQuan=r[i].roadt[j]+r[i].roadt[j+1];
            map_[ROADU].push_back({ROADV,BianQuan});
            map_[ROADV].push_back({ROADU,BianQuan});
        }
    }

    /*
    for(int i=1;i<=m;i++){
        for(int j=0;j<map_[i].size();j++){
            cout<<i<<" "<<map_[i][j].to<<" "<<map_[i][j].val<<endl;
        }
    }*/

    //dijkstra
    int tmpu,tmpv;
    for(int i=1;i<=q;i++){
        cin>>tmpu>>tmpv;
        int dis[MAXM]; memset(dis,-1,sizeof(dis));
        bool mapvis[MAXM]; memset(mapvis,0,sizeof(mapvis));
        priority_queue< pair<int,int> , vector<pair<int,int>> > pq;//pq[].first:point value   pq[].second:point id
        pq.push({0,tmpu});
        dis[tmpu]=1;
        while(!pq.empty()){
            pair<int,int> x=pq.top(); pq.pop();
            if(mapvis[x.second]) continue;
            mapvis[x.second]=1;
            //if(dis[x.second]!=x.first&&dis[x.second]==-1) continue;
            dis[x.second]=x.first;
            for(int i=0;i<map_[x.second].size();i++){
                int V=map_[x.second][i].to,W=map_[x.second][i].val;
                pq.push({x.first+W,V});
            }
        }
        cout<<dis[tmpv]+w[tmpu]+w[tmpv]<<" ";
    }
    return 0;
}
