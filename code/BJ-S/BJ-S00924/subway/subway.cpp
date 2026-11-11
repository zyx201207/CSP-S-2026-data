#include<bits/stdc++.h>
using namespace std;
struct node{long long v,c;};
long long c,n,m,d,q,x,t,minn,w[555555],k[555],dis[555][555];
vector<node> ee[555555];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=9e15;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>x>>t;
            ee[x].push_back({i,t});
        }
    }for(int i=1;i<=m;i++) for(int j=0;j<ee[i].size()-1;j++) for(int k=j+1;k<ee[i].size();k++) dis[ee[i][j].v][ee[i][k].v]=dis[ee[i][k].v][ee[i][j].v]=min(dis[ee[i][j].v][ee[i][k].v],ee[i][j].c+ee[i][k].c);
    for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) for(int k=1;k<=n;k++) dis[j][i]=dis[i][j]=min(dis[i][j],dis[j][k]+dis[i][k]);
    while(q--){
        cin>>x>>t;
        minn=9e15;
        for(int i=0;i<ee[x].size();i++) for(int j=0;j<ee[t].size();j++) minn=min(minn,dis[ee[x][i].v][ee[t][j].v]+ee[x][i].c+ee[t][j].c);
        cout<<minn+w[x]+w[t]<<'\n';
    }return 0;
}
