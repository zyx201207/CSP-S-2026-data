#include<bits/stdc++.h>
using namespace std;
long long w[500005],f[502][502];
vector<long long> g[500005],wt[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1; i<=m; i++){
        cin>>w[i];
    }
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        for(int j=1; j<=k; j++){
            long long ta,t;
            cin>>ta>>t;
            g[ta].push_back(i);
            wt[ta].push_back(t);
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1; i<=m; i++){
        for(int j=0; j<g[i].size(); j++){
            for(int k=0; k<g[i].size(); k++){
                f[g[i][j]][g[i][k]]=min(f[g[i][j]][g[i][k]],wt[i][j]+wt[i][k]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) f[i][j]=0;
        }
    }
    for(int i=1; i<=q; i++){
        int u,v;
        cin>>u>>v;
        if(u==v){
            cout<<0<<endl;
            continue;
        }
        long long ans=1e18;
        for(int j=0; j<g[u].size(); j++){
            for(int k=0; k<g[v].size(); k++){
                ans=min(ans,wt[u][j]+wt[v][k]+f[g[u][j]][g[v][k]]);
            }
        }
        cout<<ans+w[u]+w[v]<<endl;
    }
    return 0;
}