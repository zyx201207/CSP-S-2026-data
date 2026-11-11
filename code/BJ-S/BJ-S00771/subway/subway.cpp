#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>m>>n>>d>>q;
    ll f[505][505];//f[i][j]:第i条线路到第j条线路的最短路径
    memset(f,0x3f,sizeof f);
    map<pair<int,int>,int> mp;//地铁站厅到地铁站台的距离
    vector<int> g[505];//g[i]:第i条线路所经过的站点
    vector<int> t[n+1];//t[i]:经过第i个地铁站的线路
    vector<int> a(n+1);//每个地铁口到站厅的距离
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=m;++i){
        int k;
        cin>>k;
        for(int j=1;j<=k;++j){
            int t1,t2;
            cin>>t1>>t2;
            g[i].push_back(t1);
            t[t1].push_back(i);
            mp[{i,t1}]=t2;
        }
    }
    for(int i=1;i<=n;++i){
        if(t[i].size()<=1){
            continue;
        }
        //是地铁线路交汇处
        int len=t[i].size();
        for(int j1=0;j1<len;++j1){//枚举从哪条线路出发
            for(int j2=0;j2<len;++j2){//枚举到哪条线路结束
                if(j1==j2){
                    continue;
                }
                f[t[i][j1]][t[i][j2]]=min(f[t[i][j1]][t[i][j2]],1LL*mp[{t[i][j1],i}]+mp[{t[i][j2],i}]);
            }
        }
    }
    for(int i=1;i<=m;++i){
        f[i][i]=0;
    }
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int lenx=t[x].size(),leny=t[y].size();
        ll res=INF;
        for(int j1=0;j1<lenx;++j1){
            for(int j2=0;j2<leny;++j2){
                res=min(res,1LL*a[x]+mp[{t[x][j1],x}]+f[t[x][j1]][t[y][j2]]+mp[{t[y][j2],y}]+a[y]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
