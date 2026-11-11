//伍珈呈 GZ-S00058 北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20005; //500005

int c,n,m,d,q,x,y,tmp;
int w[maxn];
int a[505][maxn],t[505][maxn];
// vector<int> a[505],t[505];
// int rt[maxn][505];
vector<int> ca[505];
bool vis[maxn][maxn];

int find(int road,int now){
    for(int i=1;i<=a[road][0];i++){
        if(a[road][i]==now){
            return i;
        }
    }
    return now;
}

queue<pair<int,ll>> bl;
ll bfs(int start,int end){
    long long minn=INT_MAX;
    bl.push({start,w[start]});
    while(!bl.empty()){
        pair<int,ll> now=bl.front();bl.pop();
        // cout<<"nowpos:"<<now.first<<" "<<now.second<<'\n';
        // if(now.second>=)
        for(auto road:ca[now.first]){
            for(int i=1;i<=a[road][0];i++){
                if(a[road][i]==now.first){
                    continue;
                }
                if(a[road][i]==end){
                    // cout<<"road:"<<road<<"|from:"<<t[road][find(road,now.first)]<<"|to:"<<t[road][i]<<'\n';
                    minn=min(minn,now.second+t[road][find(road,now.first)]+t[road][i]);
                    continue;
                }
                if(!vis[now.first][a[road][i]]){
                    vis[now.first][a[road][i]]=true;
                    bl.push({a[road][i],now.second+t[road][find(road,now.first)]+t[road][i]});
                    // cout<<"lastans:"<<now.second<<"|road:"<<road<<"\t|afternow:"<<now.second+t[road][find(road,now.first)]+t[road][i]<<"|nowpos:"<<now.first<<"|goto:"<<a[road][i]<<'\n';
                    // vis[now.first][a[road][i]]=false;
                }
            }
        }
    }
    return minn;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        // a[i].push_back(tmp);
        // t[i].push_back(0);
        for(int j=1;j<=a[i][0];j++){
            cin>>a[i][j]>>t[i][j];
            // cin>>tmp;
            // a[i].push_back(tmp);
            // cin>>tmp;
            // t[i].push_back(tmp);
            ca[a[i][j]].push_back(i);
            // rt[j][i]=t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<bfs(x,y)+w[y]<<'\n';
        memset(vis,0,sizeof vis);
    }
    return 0;
}