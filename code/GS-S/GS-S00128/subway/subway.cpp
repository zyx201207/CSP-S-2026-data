#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+5;
int c,n,m,d,Q;
ll w[maxn],k[505];
vector<ll> a[505];
vector<ll> li[maxn];
ll b[505][505],dis[505][505];
map<int,ll> t[505];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) b[i][j]=dis[i][j]=INT_MAX;
    for(int i=1;i<=n;i++) b[i][i]=0;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) {
            int x,ti; cin>>x>>ti;
            a[i].push_back(x);
            li[x].push_back(i);
            t[i][x]=ti;
        }
    }
    if(n==2) {
        for(int i=1;i<=n;i++) {
            if(li[i].size()==2) b[1][2]=b[2][1]=min(b[1][2],t[1][i]+t[2][i]);
        }
    }
    else {
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                for(int ii=0;ii<k[i];ii++) {
                    for(int jj=0;jj<k[j];jj++) {
                        if(a[i][ii]==a[j][jj]) {
                            b[j][i]=b[i][j]=min(b[i][j],t[i][a[i][ii]]+t[j][a[j][jj]]);
                        }
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=b[i][j];
    for(int p=1;p<=n;p++) {
        for(int i=1;i<=n;i++) {
            if(p==i) continue;
            for(int j=1;j<=n;j++) {
                if(p==j||i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
        cout<<'\n';
    }*/
    while(Q--) {
        int x,y;
        cin>>x>>y;
        ll ans = LLONG_MAX;
        for(int i=0;i<li[x].size();i++) {
            for(int j=0;j<li[y].size();j++) {
                int lx=li[x][i], ly=li[y][j];
                ans=min(ans,dis[lx][ly]+t[lx][x]+t[ly][y]);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
    return 0;
}
