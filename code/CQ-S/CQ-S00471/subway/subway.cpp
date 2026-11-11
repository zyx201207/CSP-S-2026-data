#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,ans,dis[500003];
int k[503];
vector<pair<int,int>> line[503];
struct node{
    int w;
    vector<pair<int,int>> line;
}a[500003];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdin);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> a[i].w;
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        int j=1;
        while(j<=2*k[i]){
            int a_,t_;
            cin >> a_ >> t_;
            a[a_].line.push_back({i,t_});
            line[i].push_back({a_,t_});
            j++;
        }
    }
    while(q--){
        int x,y;
        cin >> x >> y;
        queue<int> qu;
        qu.emplace(x);
        memset(dis,0x3f,sizeof(dis));
        dis[x]=0;
        while(!qu.empty()){
            int z = qu.front();
            qu.pop();
            for(auto& it:a[z].line){
                for(auto& i:line[it.first]){
                    if(i.first!=z){
                        int u = it.second+i.second;
                        int nxt = i.first;
                        if(dis[nxt]>dis[z]+u){
                            dis[nxt]=dis[z]+u;
                            qu.push(nxt);
                        }
                    }
                }
            }
        }
        cout << a[x].w+a[y].w+dis[y]<<"\n";
    }
}