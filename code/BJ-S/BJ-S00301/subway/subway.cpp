//差不多已经有思路了，首先这个地铁是双向的，其次你可以通过的地铁（线路）走向地铁站站厅，再从站厅走到站台，从而换乘，你可以走向几个不同的站厅，再走回来……
//如何建图：
/*
首先，有几个点，按照编号来，是站台
其次，每一个站台连着地铁，地铁也同理连接着站台
每一次求出最段路（从a站台到b站台）
dijstra


包错的
*/
#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int M=510;

struct node{
    int p,len;
    bool operator<(const node other)const{
        return len>other.len;
    }
};

int c;//测试点编号 x
int n;//地铁线路数
int m;//地铁站数
int d;//每个地铁站最多被几条线路经过 x
int q;//以及出行计划数
int w[N];//地铁站地铁口走进站厅的时间（只用在进去和出来时加上）

int k[N];//k[i]表示第i条铁路的长度
int a[M][N];//a[i][j]表示第i条铁路经过的第j个站台
int t[M][N];//t[i][j]表示第i条铁路经过的第j个站台到站厅的距离

vector<node> v[N+500];//图，v[i] 假如i<=m,表示地铁站，否则是地铁线路
int vis[N+500];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            int x=a[i][j];
            int y=i+m;
            int z=t[i][j];
            v[x].push_back({y,z});
            v[y].push_back({x,z});
        }
    }
    //建图，处理

    while(q--){
        memset(vis,-1,sizeof vis);
        int s,to;
        cin>>s>>to;
        priority_queue<node>q;//这里需要修改以下，改成只会push进队列里一次！
        q.push({s,0});
        vis[s]=0;
        while(!q.empty()){
            node now=q.top();
            q.pop();
            for(auto it:v[now.p]){
                if(vis[it.p]==-1||vis[it.p]>now.len+it.len){
                    q.push({it.p,now.len+it.len});
                    vis[it.p]=now.len+it.len;
                }
            }
        }
        cout<<vis[to]+w[s]+w[to]<<endl;
    }
    return 0;
}