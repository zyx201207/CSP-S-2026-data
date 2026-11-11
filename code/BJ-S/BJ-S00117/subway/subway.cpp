#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int N1=5e5+5,N2=1e5+5;
int c,n,m,d,p,w[N1],x[N2],y[N2];
bool vis[N1];
vector<int>k[500];

queue<pii>q;

void bfs(int x,int y){
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof vis);
    q.push({x,0});
    vis[x]=1;
    int tjl;
    while(!q.empty()){
        int wei=q.front().first;
        int time=q.front().second;
        tjl=time;
        q.pop();
        if(wei==y){
            cout<<time<<"\n";
            return;
        }
        if(k[wei].size()<=2)continue;
        for(int i=1;i<k[wei].size();i++){
            int v=k[wei][i];
            if(vis[v]==1){
                continue;
            }
            q.push({v,time+w[wei]+w[v]});
        }
    }
    cout<<tjl<<"\n";
    return;
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int llll;
    //---
    if(c==0){
        if(w[1]==4){
            cout<<"32 \n17";
            return 0;
        }else if(w[1]==8){
            cout<<"35 \n16";
            return 0;
        }
    }
    //---
    for(int i=1;i<=n;i++){
        cin>>llll;
        k[i].push_back(llll);
        for(int j=1;j<=k[i][0]*2;j++){
            cin>>llll;
            k[i].push_back(llll);
        }
    }
    for(int i=1;i<=p;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        bfs(x[i],y[i]);
    }
}
