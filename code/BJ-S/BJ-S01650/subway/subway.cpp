//I love qyr
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n;
int m;
int D;
int q;
int w[500005];
vector<int> sub[500005];
int k[505];
vector<int> t[505];
long long d[1005][1005][25];
vector<int> a1[505];
vector<int> t1[505];
void dij(int s){
//    for(int i=1;i<=m;i++){
//        for(int j=0;j<=D;j++){
//            d[s][i][j]=2e18;
//        }
//    }
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
    for(int j=0;j<sub[s].size();j++){
        d[s][s][j]=t[s][j];
        q.push({t[s][j],{s,j}});
    }
    while(!q.empty()){
        auto tmp=q.top();
        q.pop();
        int u=tmp.second.first;
        int now=tmp.second.second;
        int exac=sub[u][now];
        //cout<<d[s][u][now]<<" "<<tmp.first<<" "<<u<<" "<<now<<" "<<exac<<"\n";
        if(tmp.first!=d[s][u][now]){
            continue;
        }
        for(int j=0;j<sub[u].size();j++){
            if(d[s][u][now]+t[u][j]+t[u][now]<d[s][u][j]){
                d[s][u][j]=d[s][u][now]+t[u][j]+t[u][now];
                q.push({d[s][u][j],{u,j}});
            }
        }
        for(int v:a1[exac]){
            int xl1=-1;
            for(int j=0;j<sub[v].size();j++){
                if(sub[v][j]==exac){
                    xl1=j;
                    break;
                }
            }
            if(d[s][u][now]<d[s][v][xl1]){
                d[s][v][xl1]=d[s][u][now];
                q.push({d[s][v][xl1],{v,xl1}});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(d,0x3f,sizeof d);
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x;
            int y;
            cin>>x>>y;
            a1[i].push_back(x);
            sub[x].push_back(i);
            t[x].push_back(y);
        }
    }
    for(int i=1;i<=m;i++){
        dij(i);
    }
    while(q--){
        int u;
        int v;
        cin>>u>>v;
        long long ans=2e18;
        for(int i=0;i<sub[v].size();i++){
            ans=min(ans,d[u][v][i]+t[v][i]);
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}
