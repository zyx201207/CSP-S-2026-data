#include<bits/stdc++.h>
using namespace std;
struct EDGE{
    int v;
    long long w;
};
int c,n,m,dd,q;
int a[505][1005];
int t[505][1005];
int k[505];
int w[20005];
long long d[20005];
vector<EDGE> e[20005];
vector<int> tar[20005];
void dij(int S){
    bool v[20005];
    memset(v,0,sizeof(v));
    memset(d,0x3f,sizeof(d));
    priority_queue<pair<long long,int>> q;
    d[S]=0;
    q.push({0,S});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        v[u]=false;
        //cout<<u<<endl;
        for(auto i:e[u]){
            if(d[i.v]>d[u]+i.w){
                //cout<<i.v<<" "<<d[i.v]<<endl;
                d[i.v]=d[u]+i.w;
                if(v[i.v]==false){
                    q.push({-d[i.v],i.v});
                    v[i.v]=true;
                }
            }
        }
    }
    return;
}
void SolveA(){
    for(int i=1;i<=n;i++){
        e[a[i][1]].push_back({a[i][2],t[i][1]+t[i][2]});
        e[a[i][2]].push_back({a[i][1],t[i][1]+t[i][2]});
    }
    int u,v;
    dij(1);
    while(q--){
        cin>>u>>v;
        cout<<(long long)(w[u]+w[v]+abs(d[v]-d[u]))<<"\n";
    }
    return;
}
void dij2(int S){
    bool v[20005];
    memset(v,0,sizeof(v));
    memset(d,0x3f,sizeof(d));
    priority_queue<pair<long long,int>> q;
    d[S]=0;
    q.push({0,S});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        v[u]=false;
        //cout<<u<<endl;
        for(int j:tar[u]){
            for(int jj=1;jj<=k[j];jj++){
                int i=a[j][jj];
                if(d[i]>d[u]+2){
                    d[i]=d[u]+2;
                    if(v[i]==false){
                        q.push({-d[i],i});
                        v[i]=true;
                    }
                }
            }
        }
    }
    return;
}
void SolveB(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++) tar[a[i][j]].push_back(i);
    }
    int u,v;
    dij2(1);
    while(q--){
        cin>>u>>v;
        cout<<(w[u]+w[v]+t[1][1]*(abs(d[u]-d[v])))<<"\n";
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //cout<<"ok"<<endl;
    cin>>c>>n>>m>>dd>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    if(7<=c && c<=11){
        SolveA();
        return 0;
    }
    if(12<=c && c<=19){
        SolveB();
        return 0;
    }
    return 0;
}
/*
11 4 5 20 2
4 1 9 2 5
2 1 5 2 7
1 4 6
2 2 3 3 4
1 5 7
1 3
1 2
*/
