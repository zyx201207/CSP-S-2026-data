#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[500005];
int k[509];
vector<int> a[509];
vector<ll> t[509];
vector<pair<int,ll> > su[500005];
ll v[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=501;i++){
        for(int j=1;j<=501;j++) v[i][j]=4e17;
        v[i][i]=0;
    }
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].push_back(0);
        t[i].push_back(0);
        for(int j=1;j<=k[i];j++){
            int aij,tij;
            cin>>aij>>tij;
            a[i].push_back(aij);
            t[i].push_back(tij);
            su[aij].push_back({i,tij});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<su[i].size();j++){
            for(int j2=0;j2<su[i].size();j2++){
                if(j2==j)continue;
                v[su[i][j].first][su[i][j2].first]=min(v[su[i][j].first][su[i][j2].first],su[i][j].second+su[i][j2].second);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll ans=4e17;
        for(int j=0;j<su[x].size();j++){
            for(int j2=0;j2<su[y].size();j2++){
                ans=min(ans,w[x]+w[y]+su[x][j].second+su[y][j2].second+v[su[x][j].first][su[y][j2].first]);
            }
        }
        cout<<ans<<"\n";
    }
}