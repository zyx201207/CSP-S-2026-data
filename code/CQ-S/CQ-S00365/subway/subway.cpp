/***************
 - @GavinCQTD
***************/

#include <cassert>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

ifstream fin("subway.in");
ofstream fout("subway.out");

int c,n,m,d,q;
ll w[500005],dis[505][505];
vector<pair<int,ll>> g[500005];

int main(){
    fin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        fin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        fin >> k;
        for(int j=1;j<=k;j++){
            int a,t;
            fin >> a >> t;
            g[a].push_back({i,t});
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            dis[i][j] = 1e18;
        }
    }
    
    for(int i=1;i<=m;i++){
        for(int j1=0;j1<(int)g[i].size();j1++){
            int v1=g[i][j1].first;
            ll w1=g[i][j1].second;
            for(int j2=j1+1;j2<(int)g[i].size();j2++){
                int v2=g[i][j2].first;
                ll w2=g[i][j2].second;
                dis[v1][v2] = min(dis[v1][v2],w1+w2);
                dis[v2][v1] = min(dis[v2][v1],w1+w2);
            }
        }
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][k]>=1e18||dis[k][j]>=1e18){
                    continue;
                }
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    for(int i=1;i<=q;i++){
        int x,y;
        fin >> x >> y;
        
        ll ans=1e18;
        for(auto& itm1:g[x]){
            int v1=itm1.first;
            ll w1=itm1.second;
            for(auto& itm2:g[y]){
                int v2=itm2.first;
                ll w2=itm2.second;
                ans = min(ans,w1+dis[v1][v2]+w2);
            }
        }
        
        fout << ans+w[x]+w[y] << "\n";
    }
    
    return 0;
}

/*
今年 T2 又考这种建图
为每个线路建虚点
但如何快速回答询问？、
n 和 d 都很小，从这里入手
把地铁线路钦定成点
实际上站台只起中转作用
通过站台给线路之间建边
哦吼吼做完了
*/

