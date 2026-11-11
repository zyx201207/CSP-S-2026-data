#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005],k[505];
vector<int> a[505],t[505];
struct wocao{
    int lnum,index;
};
vector<wocao>lines[500005];
struct side{
    int to;
    long long w;
};
struct state {
    int u;
    long long w;
    bool operator>(const state other) const{
        return w>other.w;
    }
};
vector<side> g[505];
bool vis[505];
long long ans[505];
void solve(){
    memset(vis,0,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    priority_queue<state,vector<state>,greater<state>> q;
    for(wocao line:lines[x]){
        q.push({line.lnum,t[line.lnum][line.index]});
    }
    while(!q.empty()){
        state s=q.top();
        q.pop();
        vis[s.u]=1;
        ans[s.u]=min(ans[s.u],s.w);
        for(side sd:g[s.u]){
            if(!vis[sd.to]){
                vis[sd.to]=1;
                q.push({sd.to,s.w+sd.w});
            }
        }
    }
    long long finalans=LONG_LONG_MAX;
    for(wocao line:lines[y]){
        long long anoth=w[x]+w[y]+ans[line.lnum]+t[line.lnum][line.index];
        finalans=min(finalans,anoth);
    }
    cout<<finalans<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    // cnmd
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int temp1,temp2;
            cin>>temp1>>temp2;
            a[i].push_back(temp1);
            t[i].push_back(temp2);
            lines[temp1].push_back({i,j-1});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<lines[i].size();j++){
            for(int k=j+1;k<lines[i].size();k++){
                wocao u=lines[i][j];
                wocao v=lines[i][k];
                side uv,vu;
                uv.to=v.lnum;
                vu.to=u.lnum;
                uv.w=vu.w=t[u.lnum][u.index]+t[v.lnum][v.index];
                g[u.lnum].push_back(uv);
                g[v.lnum].push_back(vu);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
