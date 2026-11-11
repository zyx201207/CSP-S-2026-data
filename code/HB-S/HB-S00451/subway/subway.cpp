#include<bits/stdc++.h>
using namespace std;
struct Node{int id,w;};
int c,n,m,d,q,a[20010],dis[230000];
bool vis[230000];
vector<Node> v[1100000];
void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;vis[s]=1;
    queue<int>q;q.push(s);
    while(!q.empty()){
        int x=q.front();q.pop();vis[x]=0;
        for(Node y:v[x]){
            if(dis[y.id]>dis[x]+y.w){
                dis[y.id]=dis[x]+y.w;
                if(!vis[y.id]){q.push(y.id);vis[y.id]=1;}
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k,la,uu,ww;cin>>k>>uu>>ww;la=uu;
        v[uu*201].push_back({uu*201+i,ww});
        v[uu*201+i].push_back({uu*201,ww});
        for(int j=1;j<k;j++){
            cin>>uu>>ww;
            v[uu*201].push_back({uu*201+i,ww});
            v[uu*201+i].push_back({uu*201,ww});
            v[uu*201+i].push_back({la*201+i,0});
            v[la*201+i].push_back({uu*201+i,0});
            la=uu;
        }
    }
        while(q--){
            int xx,yy;cin>>xx>>yy;spfa(xx*201);
            cout<<dis[yy*201]+a[xx]+a[yy]<<"\n";
        }
    return 0;
}
