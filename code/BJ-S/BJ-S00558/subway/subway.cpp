#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,u,v;
long long w[500050],nt,l[550][550],ans;
struct sbw{
    int kind;
    long long t;
};
vector<sbw> to[500050];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>nt;
            to[a].push_back({i,nt});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) l[i][j]=0;
            else l[i][j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto x : to[i]){
            for(auto y : to[i]){
                if(x.kind==y.kind) continue;
                if(l[x.kind][y.kind]!=-1){
                    l[x.kind][y.kind]=min(l[x.kind][y.kind],x.t+y.t);
                }else l[x.kind][y.kind]=x.t+y.t;
            }
        }
    }
    for(int o=1;o<=n;o++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(l[i][o]==-1||l[o][j]==-1) continue;
                if(l[i][j]==-1) l[i][j]=l[i][o]+l[o][j];
                else l[i][j]=min(l[i][j],l[i][o]+l[o][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        ans=-1;
        cin>>u>>v;
        if(u==v) ans=0;
        else{
            for(auto x : to[u]){
                for(auto y : to[v]){
                    if(ans==-1) ans=(w[u]+w[v]+l[x.kind][y.kind]+x.t+y.t);
                    else ans=min(ans,w[u]+w[v]+l[x.kind][y.kind]+x.t+y.t);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
