#include <bits/stdc++.h>
using namespace std;
int w[500010];
int k[512];
vector<int> a[512],t[512];
int edge[500010][512];
int c,n,m,d,q;
//position: 0/Outside 1/Hall 2/Stage
struct T{
    int station,position,line,time;
    bool operator<(T x)const{
        return time<x.time;
    }
};
int posinline(int line,int station){
    for (int i=1;i<=k[line];i++)
        if (a[line][i]==station)
            return i;
    return -1;
}
bool vis[500010][3][512];
void bfs(int from,int target){
    priority_queue<T>q;
    q.push(T{from,0,0,0});
    while (!q.empty()){
        T top=q.top();
        q.pop();
        vis[top.station][top.position][top.line]=true;
        //cout<<top.station<<" "<<top.position<<" "<<top.line<<" "<<top.time<<endl;
        if (top.station==target&&top.position==0){
            cout<<top.time<<endl;
            break;
        }
        if (top.position==0){
            if (!vis[top.station][1][0])
                q.push(T{top.station,1,0,top.time+w[top.station]});
        }else if (top.position==1){
            if (!vis[top.station][0][0])
                q.push(T{top.station,0,0,top.time+w[top.station]});
            for (int i=1;i<=n;i++)
                if (edge[top.station][i]!=0)
                    if (!vis[top.station][2][i])
                        q.push(T{top.station,2,i,top.time+edge[top.station][i]});
        }else if (top.position==2){
            int curstation=posinline(top.line,top.station);
            if (!vis[top.station][1][0])
                q.push(T{top.station,1,0,top.time+edge[top.station][top.line]});
            if (curstation!=1)
                if (!vis[a[top.line][curstation-1]][2][top.line])
                    q.push(T{a[top.line][curstation-1],2,top.line,top.time});
            if (curstation!=k[top.line])
                if (!vis[a[top.line][curstation+1]][2][top.line])
                    q.push(T{a[top.line][curstation+1],2,top.line,top.time});
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++)
        cin>>w[i];
    for (int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+3);
        t[i].resize(k[i]+3);
        for (int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            edge[a[i][j]][i]=t[i][j];
        }
    }
    //cout<<"ok."<<endl;
    for (int i=1;i<=q;i++){
        int from,to;
        cin>>from>>to;
        bfs(from,to);
        memset(vis,false,sizeof vis);
    }
    return false;
}
