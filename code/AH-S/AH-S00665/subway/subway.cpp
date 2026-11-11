#include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<vector>
#include<cmath>
#define int long long
using namespace std;
/*
输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
该测试点为样例。
输入的第二行包含 m 个正整数 w 1 , w 2 , . . . , w m ,依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2k i 个正整数,其中第一个正整数为 k i ,表
示第 i 条线路经过的地铁站数;接下来 2k i 个正整数为 a i,1 , t i,1 , a i,2 , t i,2 , . . . , a i,k i , t i,k i ,其
中 a i,j 表示第 i 条线路经过的第 j 个地铁站,t i,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 x r , y r ,分别表示第 r 个出行计
划的起点和终点所在的地铁站编号。
*/
long long w[500005];
int c,n,m,d,q,k[505],lasty,flag=1;
map<int,int> mp[505];
struct st{
    long long pos,u;
};
vector<st> subway[505];
vector<int> yuc[500005];//yuc表示这个地铁站过的地铁线路
long long bfs(int s,int t){
    long long dp[500005];
    for(int i=0;i<500005;i++)dp[i]=1e17;
    queue<st> q;
    q.push((st){s,w[s]+w[t]});//必备时间w[s]+w[t]
    dp[s]=w[s]+w[t];
    while(!q.empty()){
        //现在我在f.pos这一站.
        //我需要知道有哪些线路经过这一站
        //有第i号线过这一站
        st f=q.front();
        q.pop();
        //cout<<f.pos<<" "<<f.u<<endl;
        for(int i=0;i<yuc[f.pos].size();i++){
          //  if(mp[i][f.pos]){//地铁i号线有f.pos这一站
                int ths=yuc[f.pos][i];//我到达了ths这一条地铁线
                for(int j=0;j<subway[ths].size();j++){
                    //我在subway[ths][j]这一站
                 //   cout<<f.u+subway[ths][j].u+mp[ths][f.pos]<<" "<<dp[subway[ths][j].pos]<<endl;
                    if(f.u+subway[ths][j].u+mp[ths][f.pos]<dp[subway[ths][j].pos]){
                        q.push((st){subway[ths][j].pos,f.u+subway[ths][j].u+mp[ths][f.pos]});
                        dp[subway[ths][j].pos]=f.u+subway[ths][j].u+mp[ths][f.pos];
                        //subway[i][j].u:是第i条线中f.pos这一站与站台的距离
                    }
                }
           // }
        }
    }
  //  for(int i=1;i<=3;i++){
  //     cout<<dp[i]<<endl;
   // }
    return dp[t];
}
long long Bfs(int s,int t){
    long long minn=1e17;
    int vis[505]={0};
    queue<st> q;
    q.push((st){s,w[s]+w[t]});//必备时间w[s]+w[t]
    while(!q.empty()){
        //现在我在f.pos这一站.
        //我需要知道有哪些线路经过这一站
        //有第i号线过这一站
        st f=q.front();
        q.pop();
        //cout<<f.pos<<" "<<f.u<<endl;
        if(f.pos==t){
            minn=min(minn,f.u);
        }
        vis[f.pos]=1;
        for(int i=0;i<yuc[f.pos].size();i++){
          //  if(mp[i][f.pos]){//地铁i号线有f.pos这一站
                int ths=yuc[f.pos][i];
                for(int j=0;j<subway[ths].size();j++){
                    //我到达了subway[i][j].pos这一站
                    if(!vis[subway[ths][j].pos]){
                        q.push((st){subway[ths][j].pos,f.u+subway[ths][j].u+mp[ths][f.pos]});
                        //subway[i][j].u:是第i条线中f.pos这一站与站台的距离
                    }
                }
           // }
        }
    }
    return minn;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,x,y;j<=k[i];j++){
            cin>>x>>y;
            subway[i].push_back({x,y});
            mp[i][x]=y;//地铁i号线有x这一站，这一站的站台与站厅的距离为y
            yuc[x].push_back(i);
            if(!lasty){
                lasty=y;
            }
            else if(lasty!=y){
                flag=0;
            }
        }
    }
    //cout<<flag<<endl;
    for(int i=1,s,t;i<=q;i++){
        cin>>s>>t;
        if(!flag)
        cout<<bfs(s,t)<<endl;
        else
        cout<<Bfs(s,t)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
