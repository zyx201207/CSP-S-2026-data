#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,inf=1e18;
int C,n,m,d,q;
int w[N],len[505],f[505][505];
struct p{
    int u,v;
};
vector<p> hall[N];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            f[i][j]=inf;
            if(i==j)f[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>len[i];
        for(int j=1,u,v;j<=len[i];j++){
            cin>>u>>v;
            hall[u].push_back({i,v});
        }
    }
    for(int i=1;i<=m;i++){
        int sl=hall[i].size();
        for(int j=0;j<sl;j++){
            for(int k=j+1;k<sl;k++){
                int tmp=hall[i][j].v+hall[i][k].v,x=hall[i][j].u,y=hall[i][k].u;
                if(tmp<f[x][y])
                    f[x][y]=f[y][x]=tmp;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==k||k==j||i==j)continue;
                f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=inf;
        for(int i=0;i<hall[u].size();i++){
            for(int j=0;j<hall[v].size();j++){
                int tmp=hall[u][i].v+f[hall[u][i].u][hall[v][j].u]+hall[v][j].v;
                ans=min(ans,tmp);
            }
        }
        cout<<ans+w[u]+w[v]<<endl;
    }
    return 0;
}
//Oct31==Dec25?
