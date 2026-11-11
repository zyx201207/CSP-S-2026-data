#include<iostream>
#include<queue>
using namespace std;
long long n,m,q,u,v,w,rs,a[500001],ds[501][501];
vector<pair<long long,long long>> e[500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>n>>n>>m>>q>>q;
    for(long long i=1;i<=m;i++) cin>>a[i];
    for(long long i=1;i<=n;i++) {
        cin>>u;
        while(u--) {
            cin>>v>>w;
            e[v].push_back(make_pair(i,w));
        }
    }
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=n;j++)
            ds[i][j]=0x3f3f3f3f3f3f3f3f;
    for(long long i=1;i<=n;i++) ds[i][i]=0;
    for(long long i=1;i<=m;i++)
        for(pair<long long,long long> j:e[i])
            for(pair<long long,long long> p:e[i])
                ds[j.first][p.first]=min(ds[j.first][p.first],j.second+p.second);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=n;j++)
            for(long long p=1;p<=n;p++)
                ds[j][p]=min(ds[j][p],ds[j][i]+ds[i][p]);
    while(q--) {
        rs=0x3f3f3f3f3f3f3f3f;
        cin>>u>>v;
        for(pair<long long,long long> i:e[u])
            for(pair<long long,long long> j:e[v])
                rs=min(rs,i.second+j.second+ds[i.first][j.first]);
        cout<<a[u]+a[v]+rs<<"\n";
    }
    return 0;
}
