#include<bits/stdc++.h>
#define int long long
#define u first
#define sum second
#define INF 1e18
#define now pair<int,int>
using namespace std;
struct node{
    int v,w,id;
};
int QQQ,n,m,d,T,a[500005],dis[5005][5005],x[500005],y[500005],dis_no[500005];
int f[500005],tim=1;
vector<int> st[500005];
vector<node> q[500005];
priority_queue<now,vector<now>,greater<now> > que;
void Dij(int l,int r){
    que.push({l,a[l]});
    dis[l][l]=0;
    while(!que.empty()){
        now u=que.top();
        que.pop();
        if(f[u.u]==tim) continue;
        f[u.u]=tim;
        for(int i=0;i<q[u.u].size();i++){
            node v=q[u.u][i];
            if(dis[l][u.u]+v.w<dis[l][v.v]){
                dis[l][v.v]=v.w+dis[l][u.u];
                que.push({v.v,dis[l][v.v]});
            }
        }
    }
}
void Dij_no(int l,int r){
    que.push({l,a[l]});
    dis_no[l]=0;
    while(!que.empty()){
        now u=que.top();
        que.pop();
        if(f[r]==tim) break;
        if(f[u.u]==tim) continue;
        f[u.u]=tim;
        for(int i=0;i<q[u.u].size();i++){
            node v=q[u.u][i];
            if(dis_no[u.u]+v.w<dis_no[v.v]){
                dis_no[v.v]=v.w+dis_no[u.u];
                que.push({v.v,dis_no[v.v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>QQQ>>n>>m>>d>>T;
    for(int i=0;i<=5003;i++)
        for(int j=0;j<=5003;j++) dis[i][j]=INF;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x[j]>>y[j];
            st[x[i]].push_back(i);
        }
        for(int j=1;j<=k;j++){
            for(int o=j+1;o<=k;o++){
                q[x[j]].push_back({x[o],y[j]+y[o],i});
                q[x[o]].push_back({x[j],y[j]+y[o],i});
            }
        }
    }
    while(T--){
        int l,r;
        cin>>l>>r;
        if(m>=5005){
            memset(dis_no,0x3f,sizeof(dis_no));
            Dij_no(l,r);
            cout<<dis_no[r]+a[l]+a[r]<<"\n";
        }else{
            if(dis[l][r]!=INF) cout<<dis[l][r]+a[r]+a[l]<<"\n";
            else{
                Dij(l,r);
                cout<<dis[l][r]+a[r]+a[l]<<"\n";
            }
        }
        while(!que.empty()) que.pop();
        tim++;
    }
    return 0;
}
