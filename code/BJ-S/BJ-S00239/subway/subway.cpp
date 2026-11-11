#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int N=505;
struct eng{
    int v,t;
};
struct node{
    int pos,w;
    friend bool operator < (node x,node y) {
        if(x.w!=y.w){
            return x.w>y.w;
        }
        return x.pos>y.pos;
    }
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c;
    if(c==0) c==1;
    while(c--){
        int n,m,d,q;
        cin>>n>>m>>d>>q;
        int w[N];
        vector <eng> mp[2*n];
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            int k;
            cin>>k;
            int a[N],t[N];
            for(int j=1;j<=k;j++){
                cin>>a[j]>>t[j];
                mp[a[j]].push_back({a[j]+m,w[a[j]]+t[j]});
                mp[m+a[j]].push_back({a[j],w[a[j]]+t[j]});
            }
            for(int j=2;j<=k;j++){
                mp[a[j]].push_back({a[j-1],0});
                mp[a[j-1]].push_back({a[j],0});
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            //x+m to y+m
            vector <int> ans(N,2e9);
            vector <bool> vis(N,0);
            priority_queue <node> pq;
            pq.push({mp[m+x][0].v});
            while(!pq.empty()){
                node cur=pq.top();
                pq.pop();
                vis[cur.pos]=1;
                int u=cur.pos;
                int va=mp[u][0].v;
                if(ans[va]>ans[u]+mp[u][0].t) continue ;
                for(auto i:mp[cur.pos]){
                    int v=i.v;
                    int t=i.t;
                    if(vis[v]) continue ;
                    if(ans[u]+t<ans[v]){
                        ans[v]=ans[u]+t;
                        pq.push({v,ans[u]+t});
                    }
                }
            }
            cout<<ans[y+m]<<'\n';

        }
    }
    return 0;
}
