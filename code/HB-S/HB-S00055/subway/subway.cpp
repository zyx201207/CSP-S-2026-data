#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pi3 pair<int,pii>
#define pbi pair<bool,unsigned ll>
int lowbit(int x){
    return x&-x;
}
int c,n,m,d,q;//c 测试点编号; n 地铁线路数; m 地铁站数; d 每个地铁站最多被几条线路经过; q 出行计划数
unsigned ll w[500005];
unsigned ll ans[500005+505];
vector <pii> edge[500005+505];

void dfs(int u,int fa,unsigned ll stp,int st){
    if(ans[u]!=0) ans[u]=min(ans[u],stp);
    else ans[u]=stp;
    for (int i=0;i<edge[u].size();i++){
        int v=edge[u][i].first,w=edge[u][i].second;
        if(v==fa) continue;
        if(ans[v]!=0 and ans[v]<=stp+w) continue;
        dfs(v,u,stp+w,st);
    }
}
map<pii,pbi> mp;
pii qu[100001];
vector<int> se[100001];
int main(){
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        int u=i+m,v,w,k;
        cin>>k;
        while(k--){
            cin>>v>>w;
            edge[u].push_back({v,w});
            edge[v].push_back({u,w});
        }
    }
    for (int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        se[u].push_back(v);
        se[v].push_back(u);
        mp[{u,v}].first=0;
        qu[i].first=u,qu[i].second=v;
    }
    for (int i=1;i<=q;i++){
        int u=qu[i].first,v=qu[i].second;
        if(mp[{u,v}].first){
            cout<<(unsigned ll) mp[{u,v}].second+w[u]+w[v]<<endl;
            continue;
        }
        memset(ans,0,sizeof ans);
        dfs(u,0,0,u);
        mp[{u,v}].first=true;
        mp[{u,v}].second=ans[v];
        cout<<(unsigned ll) ans[v]+w[u]+w[v]<<endl;
        for (int j=0;j<se[u].size();j++){
            if(!mp[{u,se[u][j]}].first){
                mp[{u,se[u][j]}].first=true;
                mp[{u,se[u][j]}].second=ans[se[u][j]];
            }
            if(mp.count({se[u][j],u})){
                mp[{se[u][j],u}].first=true;
                mp[{se[u][j],u}].second=ans[se[u][j]];
            }
        }
    }
    return 0;
}