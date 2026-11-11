#include <bits/stdc++.h>
using namespace std;
#define int long long

int c,n,m,d,q;
const int N=507;
const int M=5e5+7;
int w[M];
int k[N];
//int a[N][M];
int t[N][M];
bool havedis[N][N];
int dis[N][N];
int sl[M][21];
int sli[M]={};
bool havemind[N][N];
//int mind[N][N];

struct node{
    int l;
    int d;
};

bool operator < (node x,node y){
    return x.d>y.d;
}

int bfs(int l1,int l2){
    if(havemind[l1][l2])return dis[l1][l2];
    bool vis[N]={};
    for(int i=1;i<=n;i++)vis[i]=false;
    priority_queue<node> q={};
    q.push({l1,0});
    vis[l1]=true;
    while(!q.empty()){
        node topnode=q.top();
        q.pop();
        for(int i=1;i<=n;i++){
            if(!havedis[topnode.l][i])continue;
            if(i==topnode.l)continue;
            if((!vis[i])||topnode.d+dis[topnode.l][i]<dis[l1][i]){
                q.push({i,topnode.d+dis[topnode.l][i]});
                dis[l1][i]=dis[i][l1]=topnode.d+dis[topnode.l][i];
                havedis[l1][i]=havedis[i][l1]=true;
                havemind[l1][i]=havemind[i][l1]=true;
                vis[i]=true;
            }
        }
    }
    return dis[l1][l2];
}

int way(int stx,int sty){
    bool hd=false;
    int mindis=0;
    for(int i=1;i<=sli[stx];i++){
        int l1=sl[stx][i];
        for(int j=1;j<=sli[sty];j++){
            int l2=sl[sty][j];
            int d=t[l1][stx]+bfs(l1,l2)+t[l2][sty];
            if((!hd)||d<mindis){
                mindis=d;
                hd=true;
            }
        }
    }
    return mindis;
}

signed main(){
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int st=1;st<=m;st++)cin>>w[st];
    for(int l=1;l<=n;l++){
        cin>>k[l];
        for(int i=1;i<=k[l];i++){
            int st;//a[l][i]
            cin>>st;
            cin>>t[l][st];
            sl[st][++sli[st]]=l;
        }
    }
    for(int l=1;l<=n;l++)havedis[l][l]=havemind[l][l]=true;
    for(int st=1;st<=m;st++){
        for(int i=1;i<=sli[st];i++){
            int l1=sl[st][i];
            for(int j=i+1;j<=sli[st];j++){
                int l2=sl[st][j];
                int d=t[l1][st]+t[l2][st];
                if((!havedis[l1][l2])||dis[l1][l2]>d){
                    dis[l1][l2]=dis[l2][l1]=d;
                    havedis[l1][l2]=true;
                }
            }
        }
    }
    while(q--){
        int stx,sty;
        cin>>stx>>sty;
        int d=way(stx,sty);
        cout<<w[stx]+d+w[sty]<<endl;
    }
    return 0;
}
