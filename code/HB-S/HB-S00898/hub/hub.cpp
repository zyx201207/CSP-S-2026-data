#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct EDGE{
    int to,next,w;
}edge[N<<2];
int dist[1005][1005];
int head[N],cnt;
void add(int x,int y){
    edge[++cnt].to=y;
    edge[cnt].next=head[x];
    edge[cnt].w=1;
    head[x]=cnt;
}
int fa[N];
int find(int x){
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}
int c,t,n,k;
int ans;
vector<int> k1;
bool ink1[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            add(x,y);
            add(y,x);
        }
        for(int i=1;i<=k;i++){
            //k=1
            for(int j=1;j<=n;j++){
                if(ink1[j])continue;
                k1.push_back(j);
                ink1[j]=true;
            }
        }
        //floyd();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                dist[i][j]=1e16;
            }
        }
        int v,w;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=head[i];k;k=edge[i].next){
                    v=edge[i].to,w=edge[i].w;
                    if(dist[i][j]>dist[i][v]+dist[v][j]+w){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    return 0;
}