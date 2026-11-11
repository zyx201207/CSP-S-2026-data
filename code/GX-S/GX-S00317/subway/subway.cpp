#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll c,n,m,d,q;
ll w[N];
ll a[4005][4005],t[4005][4005];
ll k[N];
bool vis[N];
struct node{
    int to,nxt,w;
}e[N];
//ll d[N];
ll head[N];
ll tot=0;
/*void add(int u,int v,int w){
    ++tot;
    e[tot].to=v;
    e[tot].w=w;
    e[tot].nxt=head[u];
    head[u]=tot;
}
void init(){
    memset(e,0,sizeof(e));
    memset(head,0,sizeof(head));
    tot=0;
}
void dij(int s){
    init();
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=N;i++) d[i]=1e18;
    pq.push({0,s});
    d[s]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            int w=e[i].w;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                pq.push({-d[v],v});
            }
        }
    }

}
vector<int> aa(N);
vector<int> tt(N);*/
int sum[N];
int cnt1=0;
int main(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++) {
            cin>>a[i][j]>>t[i][j];
            cnt1++;
            sum[cnt1]=a[i][j];
        }
    }
    sort(sum+1,sum+cnt1+1);
    int ans=0;
    while(q--){
        int st,en;
        cin>>st>>en;
        cout<<w[st]+
    }
    return 0;
}
