#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],t[510][500010];
vector<pair<int,int>> g[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int u=0;
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            t[i][x]=y;
            if(u!=0){
                g[u].push_back({x,i});
                g[x].push_back({u,i});
            }
            u=x;
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        for(int j=1;j<=n;j++){
            if(t[j][x]&&t[j][y]){
                cout<<w[x]+w[y]+t[j][x]+t[j][y]<<"\n";
                break;
            }
        }
    }
    return 0;
}
