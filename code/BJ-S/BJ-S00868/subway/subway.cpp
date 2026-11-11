#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500100];
vector<int> sts[500100];
vector<pair<int,int> > station[510];
int dis[500100];
bool vis[500100];
void dij(int st,int ed){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    dis[st]=w[st]+w[ed];
    for(auto s:sts[st]){
        for(int i=0;i<station[s].size();i++){
            if(station[s][i].first==st){
                int tiim=station[s][i].second,vv=station[s][i].first;
                pq.push({tiim,vv});
            }
        }
    }
    while(!pq.empty()){
        int sttt=pq.top().second;
        int timm=pq.top().first;
        pq.pop();
        if(vis[sttt])continue;
        vis[sttt]=1;
        //cout<<"on station:"<<sttt<<",and the station to halls time is:"<<timm<<",to "<<sttt<<"s time is:"<<dis[sttt]<<"\n";
        for(auto son:station[sttt]){
            int r=son.first;
            int w=son.second;
            if(dis[r]>dis[sttt]+w+timm){
                dis[r]=dis[sttt]+w+timm;
                pq.push({dis[r],r});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int sta,tim;
            cin>>sta>>tim;
            sts[sta].push_back(i);//zhe_ge_zhan_tai_ke_yi_dao_na_xie_di_tie_shang
            station[i].push_back({sta,tim});//zhe_ge_ti_tie_ke_yi_dao_na_xie_zhan_tai
        }
    }
    while(q--){
        int st,ed;
        cin>>st>>ed;
        dij(st,ed);
        cout<<dis[ed]<<"\n";
    }
}
//TAT,bu_yao_gao_wa,TAT