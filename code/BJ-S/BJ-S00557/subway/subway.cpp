#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+50,M=505,P=1e3+37,D=25,INF=1e18;
int c,n,m,d,q,w[P];
vector<pair<int,int>> vec[M*P];
pair<int,int> pii[P][D];
int vis_cnt[P];
int dist[P][P],dist_dijk[M*P];
bool vis_dijk[P];
bool vis[P*M];

struct node{
    int id,wt;
    bool fl1,fl2;
    int t1,t2;
}tr[N];

void tfo_dijk(){
    /*
    for(int i=1;i<=(m+1)*n;i++){
        if(dist_dijk[i]>=1e9){
            cout<<"INF"<<" ";
            continue;
        }
        cout<<dist_dijk[i]<<' ';
    }
    cout<<'\n';
    */
}
void dijk(int st){
    memset(vis,0,sizeof vis);
    memset(dist_dijk,0x3f3f3f3f,sizeof dist_dijk);
    priority_queue<pair<int,int>> pq;
    pq.push({0,st});
    dist_dijk[st]=0;
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        if(vis[p.second]){
            continue;
        }
        vis[p.second]=1;
        for(int i=0;i<vec[p.second].size();i++){
            int v=vec[p.second][i].first,wor=vec[p.second][i].second;
            if(dist_dijk[v]>=dist_dijk[p.second]+wor){
                dist_dijk[v]=dist_dijk[p.second]+wor;
                pq.push({-dist_dijk[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        dist[st][i]=dist_dijk[i];
    }
}
void tfo(){
    /*
    for(int i=1;i<=(m+1)*n;i++){
        cout<<i/n<<" "<<i%n<<'\n';
        for(pair<int,int> j:vec[i]){
            cout<<j.first<<" "<<j.second<<'\n';
        }
        cout<<'\n';
    }
    */
    /*
    for(int i=1;i<=n;i++){
        cout<<i<<'\n';
        for(pair<int,int> j:pii[i]){
            if(j.first!=0&&j.second!=0){
                cout<<j.first<<" "<<j.second<<'\n';
            }
        }
        cout<<'\n';
    }
    */
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]>1e9){
                cout<<"INF"<<' ';
            }else{
                cout<<dist[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
    */
}
void solve(){
    for(int i=1;i<=n;i++){
        cin>>tr[i].wt;
    }
    int k,minn=INF;
    cin>>k;
    for(int i=1;i<=k;i++){
        int st,t;
        cin>>st>>t;
        tr[st].fl1=1;
        tr[st].t1=t;
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        int st,t;
        cin>>st>>t;
        tr[st].fl2=1;
        tr[st].t2=t;
    }
    for(int i=1;i<=n;i++){
        if(tr[i].fl1&&tr[i].fl2){
            minn=min(minn,tr[i].t1+tr[i].t2);
        }
    }
    while(q--){
        int xr,yr,minx=INF;
        cin>>xr>>yr;
        if(tr[xr].fl1&&tr[yr].fl1){
            minx=min(minx,tr[xr].wt+tr[xr].t1+tr[yr].t1+tr[yr].wt);
        }
        if(tr[xr].fl2&&tr[yr].fl1){
            minx=min(minx,tr[xr].wt+tr[xr].t2+tr[yr].t1+tr[yr].wt+minn);
        }
        if(tr[xr].fl1&&tr[yr].fl2){
            minx=min(minx,tr[xr].wt+tr[xr].t1+tr[yr].t2+tr[yr].wt+minn);
        }
        if(tr[xr].fl2&&tr[yr].fl2){
            minx=min(minx,tr[xr].wt+tr[xr].t2+tr[yr].t2+tr[yr].wt);
        }
        cout<<minx<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>m>>n>>d>>q;
    if(n<=2){
        solve();
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        int k,lst=-1;
        cin>>k;
        for(int j=1;j<=k;j++){
            int st,t;
            cin>>st>>t;
            pii[st][++vis_cnt[st]]={i,t};
            if(lst==-1){
                lst=st;
            }else{
                vec[st+n*i].push_back({lst+n*i,0});
                vec[lst+n*i].push_back({st+n*i,0});
                lst=st;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=vis_cnt[i];j++){
            for(int k=j+1;k<=vis_cnt[i];k++){
                if(j==0){
                    vec[i+pii[i][k].first*n].push_back({i,w[i]+pii[i][k].second});
                    vec[i].push_back({i+pii[i][k].first*n,w[i]+pii[i][k].second});
                }else{
                    vec[i+pii[i][k].first*n].push_back({i+pii[i][j].first*n,pii[i][k].second+pii[i][j].second});
                    vec[i+pii[i][j].first*n].push_back({i+pii[i][k].first*n,pii[i][k].second+pii[i][j].second});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        dijk(i);
    }
    while(q--){
        int xr,yr;
        cin>>xr>>yr;
        cout<<dist[xr][yr]<<'\n';
    }
    return 0;
}
