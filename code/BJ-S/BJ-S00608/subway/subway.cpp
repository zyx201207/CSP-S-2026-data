#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[20005],t[505][20005],mindis[505][20005],vis[505][20005],a[25][20005],sz[20005];
struct node{
    int xl,to,val;
    bool operator<(const node& a)const{
        return val>a.val;
    }
};
vector<node>gp[20005];
priority_queue<node>p_q;
void dij(int st){
    for(int i=1;i<=sz[st];i++){
        int xl=a[i][st],val=w[st]+t[xl][st];
        mindis[xl][st]=min(mindis[xl][st],val);
        p_q.push((node){xl,st,val});
    }
    while(!p_q.empty()){
        auto qf=p_q.top();
        p_q.pop();
        if(vis[qf.xl][qf.to])continue;
        vis[qf.xl][qf.to]=1;
        for(auto it:gp[qf.to]){
            int val=0;
            if(it.xl!=qf.xl)val=t[qf.xl][qf.to]+t[it.xl][qf.to];
            if(mindis[qf.xl][qf.to]+val<mindis[it.xl][it.to]){
                p_q.push((node){it.xl,it.to,mindis[it.xl][qf.to]+val});
                mindis[it.xl][it.to]=mindis[qf.xl][qf.to]+val;           
                   
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int lst=0;
        for(int j=1;j<=k;j++){
            int aa;
            cin>>aa>>t[i][j];
            a[++sz[aa]][aa]=i;
            gp[lst].push_back((node){i,aa,0});
            lst=aa;
        }
    }
    while(q--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mindis[i][j]=1e18;
                vis[i][j]=0;
            }
        }
        int u,v;
        cin>>u>>v;
        dij(u);
        int ans=LLONG_MAX;
        for(int i=1;i<=n;i++)ans=min(ans,mindis[i][v]+t[i][v]+w[v]);
        cout<<ans<<endl;
    }
    return 0;
}
/*

idea:
1:fen ceng tu
2:baoli dij
*/