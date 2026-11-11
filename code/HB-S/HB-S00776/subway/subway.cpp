#include<bits/stdc++.h>
#define int long long
using namespace std;

int w[1010];
int dist[1010][1010];
int dl[1010][1010];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,n,m,d,ql;
    cin>>c>>n>>m>>d>>ql;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dist[i][j]=1e18;
            dl[i][j]=1e18;
            if(i==j){
                dist[i][i]=0;
                dl[i][i]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k==1){
            cin>>k>>k;
            continue;
        }
        vector<int>h,t;
        for(int j=1;j<=k;j++){
            int hl,tl;
            cin>>hl>>tl;
            h.push_back(hl);
            t.push_back(tl);
        }
        for(int j=1;j<k;j++){
            for(int l=j-1;l>=0;l--){
                dist[h[l]][h[j]]=dist[h[j]][h[l]]=min(dist[h[l]][h[j]],t[l]+t[j]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        queue<int>q;
        bool vis[1010]={};
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int j=1;j<=m;j++){
                if(j==u) continue;
                if(dl[i][j]>=dl[i][u]+dist[u][j]){
                    dl[i][j]=dl[i][u]+dist[u][j];
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=ql;i++){
        int x,y;
        cin>>x>>y;
        cout<<dl[x][y]+w[x]+w[y]<<endl;
    }//1-11 44pts
    return 0;
}
