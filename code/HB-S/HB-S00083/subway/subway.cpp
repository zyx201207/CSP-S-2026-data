#include<bits/stdc++.h>
using namespace std;
struct Node{
    int id;
    int p=0;
    int w;
    vector<int> f;
    int n[500];
}me[500];
int su[500][200];
bool vis[500];
void solve(){
    memset(vis,0,sizeof(vis));
    queue<Node> qu;
    int x,y;
    cin>>x>>y;
    vis[x]=1;
    me[x].p+=me[x].w;
    qu.push(me[x]);
    while(!qu.empty()){
        if(qu.front().id==y){
            cout<<qu.front().p<<endl;
            return;
        }
        Node cur=qu.front();
        for(auto &x:cur.f){
            int np=cur.p+cur.n[x];
            int now=1;
            while(su[x][now]!=0&&vis[me[su[x][now]].id]==0){
                vis[me[su[x][now]].id]==1;
                Node son=me[su[x][now]];
                son.p=np+son.w;
                qu.push(son);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>me[i].w;
        me[i].id=i;
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            su[i][j]=a;
            me[a].f.push_back(i);
            me[a].n[i]=t;
        }
    }
    for(int i=0;i<q;i++){
        solve();
    }
}
