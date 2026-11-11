#include<bits/stdc++.h>
#define x first
#define y second

#define ll long long
#define pil pair<int,ll>
//floyd is enable;
using namespace std;
const int M=5e5+10,N=505,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,tot[M],k[M];
ll dist[N][N],ans,w[N];
pil node[M][21];
int id;
ll tim;
//vector<int>v[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    memset(dist,0x3f,sizeof dist);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>id>>tim;
            node[id][tot[id]++]={i,tim};
            //v[i].push_back({tim});
        }
    }
    pil s,e;
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
        for(int j=0;j<tot[i];j++){
            for(int k=j+1;k<tot[i];k++){
                s=node[i][j],e=node[i][k];
                dist[s.x][e.x]=dist[e.x][s.x]=min(dist[s.x][e.x],(s.y+e.y));
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int l,r;
    while(q--){
        cin>>l>>r;
        ans=inf;
        for(int i=0;i<tot[l];i++){
            for(int j=0;j<tot[r];j++){
                s=node[l][i];
                e=node[r][j];
                ans=min(ans,dist[s.x][e.x]+w[l]+w[r]+s.y+e.y);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

