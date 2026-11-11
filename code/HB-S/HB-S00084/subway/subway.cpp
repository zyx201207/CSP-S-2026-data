#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    vector<long long> w;
    vector<vector<long long>> t;
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<vector<long long>> g;
    vector<vector<vector<long long>>> dp;
    for(long long i=0;i<m+1;i++){
        dp.push_back({});
        g.push_back({});
        for(long long j=0;j<m+1;j++){
            g[i].push_back(0);
            dp[i].push_back({});
            for(long long k=0;k<m+1;k++){
                dp[i][j].push_back(0);
            }
        }
    }
    for(long long i=0;i<m;i++){
        long long wa;
        cin>>wa;
        w.push_back(wa);
    }
    for(long long i=0;i<n;i++){
        long long k;
        cin>>k;
        for(long long j=0;j<k;j++){
            long long z,ti;
            cin>>z>>ti;
            for(long long jj=j+1;jj<k;jj++){
                long long zz,tii;
                cin>>zz>>tii;
                g[z][zz]==min(g[z][zz],tii+ti);
                g[zz][z]==min(g[zz][z],tii+ti);
            }
        }
    }
    for(long long k=0;k<m;k++){
        for(long long i=0;i<m;i++){
            for(long long j=0;j<m;j++){
                dp[k+1][i+1][j+1]=min(dp[k][i+1][j+1],dp[k+1][i+1][k+1]+dp[k+1][k+1][j+1]+g[i][k]+g[k][j]);
            }
        }
    }
    for(long long i=0;i<q;i++){
        long long u,v;
        cin>>u>>v;
        cout<<dp[u+1][v+1][m]+w[u]+w[v]<<endl;
    }
    return 0;
}
