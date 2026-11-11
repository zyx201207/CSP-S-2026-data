#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define x first
#define y second
#define ls p<<1
#define rs p<<1|1
#define pb push_back

const int N=510,M=2e4+10;
int n,m,c,d,q,w[M],k[N],a[N][M],x,y,t[N][M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    //
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];

    }
    vector<PII> g[n+1][m+1],b[m+1];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            g[i][a[i][j-1]].pb({a[i][j],t[i][j]});
            b[a[i][j]].pb({i,t[i][j]});
        }

    }

    while(q--){
        cin>>x>>y;
        priority_queue<array<int,3> > h;
        int st[n+1][m+1],d[N][N];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) st[i][j]=0,d[i][j]=M;
        }
        //{ distance,seat,road }
        for(int i=0;i<b[x].size();i++){
            h.push({-(w[x]+b[x][i].y),x,b[x][i].x});
            d[b[x][i].x][x]=min(w[x]+b[x][i].y,d[b[x][i].x][x]);
        }

        while(h.size()){
            auto p=h.top();
            h.pop();
            int u=p[1],x=p[2];
            if(st[x][u])continue;
            st[x][u]=1;
            //cout<<u<<" "<<x<<" "<<p[0]<<endl;
            for(int i=0;i<g[x][u].size();i++){
                int k=g[x][u][i].x,v=g[x][u][i].y;
                if(d[x][k]>d[x][u]+v){
                    d[x][k]=d[x][u]+v;

                    h.push({-d[x][k],k,x});
                }
            }
            for(int i=0;i<b[u].size();i++){
                int k=b[u][i].x,v=b[u][i].y;
                if(d[x][u]+v<d[k][u]){
                        d[k][u]=d[x][u]+v;
                    h.push({-(d[x][u]+v),u,k});
                }

            }
        }
        int ans=M;
        for(int i=1;i<=n;i++){
            ans=min(d[i][y]+w[y],ans);
        }
        cout<<ans<<endl;
    }
}
