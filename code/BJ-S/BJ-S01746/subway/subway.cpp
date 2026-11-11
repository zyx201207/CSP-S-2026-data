#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

#define int long long 
const int M=5e5+10,MP=1.5e6+10,N=5e2+10;
int w[M],cnt;
int d[N][N];
vector<pair<int,int> > chg[M];

signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(d,0x3f,sizeof d);
    int c,n,m,D,q;cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=1,k;i<=n;i++) {
        cin>>k;
        for(int j=1,x,y;j<=k;j++) {
            cin>>x>>y;chg[x].push_back({i,y});
        }
    }
    // cout<<"P1"<<endl;
    for(int i=1;i<=m;i++) {
        int k=chg[i].size()-1;
        for(int a=0;a<=k;a++) {
            for(int b=0;b<=k;b++) {
                d[chg[i][a].first][chg[i][b].first]=
                    min(d[chg[i][a].first][chg[i][b].first],chg[i][a].second+chg[i][b].second);
            }
        }
    }
    // cout<<"P2"<<endl;
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(d[i][j]>d[i][k]+d[k][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    // cout<<"P3"<<endl;
    for(int i=1,x,y,ret=0;i<=q;i++) {
        cin>>x>>y;ret=1e18+7;
        int k1=chg[x].size()-1;
        int k2=chg[y].size()-1;
        for(int a=0;a<=k1;a++) {
            for(int b=0;b<=k2;b++) {
                ret=min(ret,
                    d[chg[x][a].first][chg[y][b].first]+chg[x][a].second+chg[y][b].second);
            }
        }
        cout<<ret+w[x]+w[y]<<'\n';
    }
    cout<<endl;
    return 0;
}