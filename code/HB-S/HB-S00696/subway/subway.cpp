#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int MAXN=505,MAXM=500005;
struct Node {int tim,plc;};
int c,n,m,d,q,w[MAXM],f[MAXN][MAXN];
vector <int> E[MAXN];
vector <Node> gett[MAXM];
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q; 
    for (int i=1;i<=m;i++) cin>>w[i];
    for (int i=1;i<=n;i++) {
        int cnt; cin>>cnt;
        for (int j=1;j<=cnt;j++) {
            int x,y; cin>>x>>y; gett[x].pb({y,i});
        }
    } for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i!=j) f[i][j]=2e18;
        }
    } for (int i=1;i<=m;i++) {
        for (int get1=0;get1<gett[i].size();get1++) {
            for (int get2=get1+1;get2<gett[i].size();get2++) {
                Node vtoa=gett[i][get1],vtob=gett[i][get2];
                f[vtoa.plc][vtob.plc]=min(f[vtoa.plc][vtob.plc],vtoa.tim+vtob.tim);
                f[vtob.plc][vtoa.plc]=min(f[vtob.plc][vtoa.plc],vtoa.tim+vtob.tim);
            }
        }
    } for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    } for (int i=1;i<=q;i++) {
        int x,y,answ=2e18; cin>>x>>y; for (int get1=0;get1<gett[x].size();get1++) {
            for (int get2=0;get2<gett[y].size();get2++) {
                Node vtoa=gett[x][get1],vtob=gett[y][get2];
                answ=min(answ,f[vtoa.plc][vtob.plc]+vtoa.tim+vtob.tim+w[x]+w[y]);
            }
        }
        printf("%lld\n",answ);
    }
    return 0;
}