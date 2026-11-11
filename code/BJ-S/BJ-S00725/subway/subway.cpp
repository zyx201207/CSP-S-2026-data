/*
我常常追忆过去。
生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。
云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的好，那恰到好处的朦胧，才能满足我对美的苛求。
追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客，但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，站在岁月的朦胧里瞭望过去的自己。美好的时光曾流过我的身体，我便心满意足。
过去已经凝固，我带着回忆向前。只是时常疏于保管，回忆也在改变着各自的形态，这给我的追忆旅程带来些许挑战。
我该在哪里停留？我问我自己。
*/
#include<bits/stdc++.h>
using namespace std;
constexpr int N=505,M=500005,D=20,Q=100005;
constexpr long long inf=1000000000000000ll;
int id,n,m,d,q,w[M];
long long dis[N][N];
vector<pair<int,int> >v[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>id>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k,a,t;i<=n;i++){
        cin>>k;
        while(k--){
            cin>>a>>t;
            v[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=m;i++){
        for(pair<int,long long> j:v[i])
        for(pair<int,long long> k:v[i])
        dis[j.first][k.first]=min(dis[j.first][k.first],j.second+k.second);
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=inf;
        for(pair<int,int> j:v[x])
        for(pair<int,int> k:v[y])
        ans=min(ans,dis[j.first][k.first]+j.second+k.second);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
/*
有 500 条线路,每个站最多有 20 条线路,最小化换乘时间.1e5 次询问,5e5 个站.
从站 x 用线路 i 到 y 的时间:t[i][x 的下标]+t[i][y 的下标].
不妨线路作点,总边数为 \sum k.
考虑 d=20,n=500 对多组询问的影响.
关键点最短路.只统计线路与线路间的最短路,时间为 (m+q)n...吗?
实现好像有点问题.每个点只多连 20 条线路,那就用点来更新 e[线路].
时间是 m*d^2 + n^3 +... qn^2?噢噢噢是 qd^2.
好像有点卡常?
*/