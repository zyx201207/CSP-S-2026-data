/*
1502:that's for subway.开B。
1504:题有点难读。图论打磨你。
1507:多源最短路？
1509:我力竭了怎么这么多输入。
1514:之前有个trick是把上下车看作一个点。手摸以下阳历把。
1521:对啦喵～就是这个哦！考虑复杂度。考虑最劣情况，每个线都经过所有站。
此时空间......等会，我想起了去年T2开小了然后爆炸了。1024mib欸。
坏了我不会算空间。但一共有n+m个点.500500不可能爆。
那时间呢？最多的边数为nm。这dij会T阿。
1528:考虑把询问离线。我们处理相同起点的询问，只用一次dij。
1531:注意到题目中每个地铁站最多被20条线路经过。那咱们接着构造。直接把n简化成20
1535:我现在急需证明时间复杂度能过。别慌。
1537:我觉得我们需要回到问题的本源。dij在N个点，M条边的情况下是O(N log M)的吗？
好像是O(M log N)的？晚餐，我好想网球。不管怎么说，写一边可以考虑看下。
1543:好吧是O(M log N)的。M=(20*5e5)=1e8 不是？？？
1548:这啥意思。N=5e5。看起来我们不能够得到全部的分数了。片分把。
我的做法是O(q M log N)的。其中M=md，N=m，能过1~8。
1553:不能再想太久了。写把。
1601:sub5能跑过？
1604:44pts get.想到15，如果没有新的思路就跳。
1613:上厕所，遇到了meinvshe(lbq)，
1616:把q变成一个一定<=q的值。这个对性质A尤其有效。
那么需要对q排序。就是O(q log q + qM log N)的了。不行。
1622:打住。跳。
*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10+1000;
long long _,n,m,ans,a[N],sum[N];
long long kou[N],dis[N],d,q;
bool p[N];
vector<pair<int,long long> > g[N];
inline void dij(int s){
    for(int i=1;i<=n+m+10;i++){
        dis[i]=2e18,p[i]=0;
    }
    priority_queue<pair<long long,int> > q;
    q.push({-0,s}),dis[s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(p[u])continue;
        p[u]=1;
        for(pair<int,long long> tmp : g[u]){
            long long v=tmp.first,w=tmp.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!p[v])q.push({-dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>_>>n>>m>>d>>q;//线路数，站数，最多多少条线路经过，出行计划数。
    for(int i=1;i<=m;i++){
        cin>>kou[i];//口厅时间
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            long long t1,t2;
            cin>>t1>>t2;
            //站名，厅台时间
            g[t1].push_back({i+m,t2});
            g[i+m].push_back({t1,t2});
        }
    }
    while(q--){
        int st,ed;
        cin>>st>>ed;
        dij(st);
        cout<<dis[ed]+kou[st]+kou[ed]<<"\n";
    }
    return 0;
}