#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,tt;
int nw,tot,a[N];
ll dis[N],t[N],ans[N];
vector<pair<int,int> > e[N];
bool vis[N];
struct node{
    int id;
    ll dis;
    bool operator <(const node &o) const{
        return dis>o.dis;
    }
};
struct input{
    int st,ed,id;
}qq[N];
bool cmp(input x,input y){
    return x.st<y.st;
}
priority_queue<node> pq;
void dij(int s){
    for(int i=1;i<=tot;i++) dis[i]=inf,vis[i]=false;
    dis[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        node tmp=pq.top(); pq.pop();
        int u=tmp.id;
        //cout<<u<<" ";
        if(vis[u]) continue;
        vis[u]=true;
        tt++;
        for(auto it:e[u]){
            int v=it.first,w=it.second;
            if(!vis[v] && dis[u]+w < dis[v]){
                dis[v]=dis[u]+w;
                pq.push({v,dis[v]});
            }
        }
    }
}

int main(){
    //freopen("subway.in","w",stdout);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(t,0x3f,sizeof(t));
    cin>>c>>m>>n>>d>>q;
    tot=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int k,fst,lst,u,w;
        ll sum=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>u>>w;
            e[u].push_back({++tot,w});
            e[tot].push_back({u,w});
            if(j!=1){
                e[lst].push_back({tot,0});
                e[tot].push_back({lst,0});
            }
            else fst=u;
            lst=tot;
            sum+=w;
        }
        t[fst]=min(t[fst],sum);
    }
    if(20<=c && c<=21){
        while(q--){
            int st,ed;
            cin>>st>>ed;
            cout<<t[st]+a[st]+a[ed]<<"\n";
        }
        return 0;
    }
    //cout<<tot<<endl;
    if(c<=15){
        for(int i=1;i<=q;i++){
            cin>>qq[i].st>>qq[i].ed;
            qq[i].id=i;
        }
        sort(qq+1,qq+q+1,cmp);
        for(int i=1;i<=q;i++){
            if(nw!=qq[i].st){
                nw=qq[i].st;
                tt=0;
                dij(qq[i].st);
            }
            ans[qq[i].id]=dis[qq[i].ed]+a[qq[i].st]+a[qq[i].ed];
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
        return 0;
    }
    return 0;
}
/*
20 4 2 10 2
2 1 3 2 6
2 1 7 2 1
2 2 3 1 2
2 2 4 1 5
*/
