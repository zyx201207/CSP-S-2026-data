#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],dis[500005];
struct node{
    int li,t;
};
vector<node> tree[500005];
vector<node> tree2[505];
int bfs(int s,int e){
    queue<int> que;
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    que.push(s);
    while(!que.empty()){
        int cur=que.front(); que.pop();
        if(cur==e){
            return dis[e]+w[s]+w[e];
        }
        for(int i=0;i<tree[cur].size();i++){
            int k=tree[cur][i].li,t1=tree[cur][i].t;
            for(int j=0;j<tree2[k].size();j++){
                int v=tree2[k][j].li,t=tree2[k][j].t;
                if(dis[cur]+t+t1<dis[v]){
                    dis[v]=dis[cur]+t+t1;
                    que.push(v);
                }
            }
        }
    }
    return 0;
}
signed main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++){
    int k,a,t;
    cin>>k;
    for(int j=1;j<=k;j++){
        cin>>a>>t;
        tree[a].push_back({i,t});
        tree2[i].push_back({a,t});
    }
}
while(q--){
    int l,r;
    cin>>l>>r;
    cout<<bfs(l,r)<<"\n";
}
return 0;
}
