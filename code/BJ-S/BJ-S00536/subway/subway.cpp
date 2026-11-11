#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
namespace rp{
    void slow() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    const int N=507;
    const int M=5e5+7;
    int f[N][N],a[M][2],t[M];
    vector<pii> e[M];
    inline void fl() {
        slow();
        int n,m,d,q;cin>>n>>m>>d>>q;
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=n;i++)f[i][i]=0;
        for(int i=1;i<=m;i++) cin>>t[i];
        for(int i=1;i<=n;i++) {
            int k;cin>>k;
            for(int j=1;j<=k;j++) {
                cin>>a[j][0]>>a[j][1];
                e[a[j][0]].push_back({i,a[j][1]});
            }
        }
        for(int i=1;i<=m;i++) {
            for(int j=0;j<e[i].size();j++) {
                for(int k=0;k<j;k++) {
                    f[e[i][j].x][e[i][k].x]=f[e[i][k].x][e[i][j].x]=min(f[e[i][k].x][e[i][j].x],e[i][j].y+e[i][k].y);
                }
            }
        }
        for(int j=1;j<=n;j++) {
            for(int i=1;i<=n;i++) {
                for(int k=1;k<=n;k++) {
                    f[i][k]=f[k][i]=min(f[i][k],f[i][j]+f[j][k]);
                }
            }
        }
        while(q--) {
            int x,y;cin>>x>>y;
            int ans=1e18+7;
            for(int i=0;i<e[x].size();i++) {
                for(int j=0;j<e[y].size();j++) {
                    ans=min(ans,f[e[x][i].x][e[y][j].x]+e[x][i].y+e[y][j].y);
                }
            }
            cout<<ans+t[x]+t[y]<<'\n';
        }
    }/*
    void sub2() {

    }*/
    inline void main() {
        int c;cin>>c;
        fl();
        //if(c==21||c==20) sub2();
    }
}
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    rp::main();
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
