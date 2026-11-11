#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pb push_back
#define pii pair<int,int>
#define endl '\n'
#define x first
#define y second
int c,n,m,d,q,w[500010],k[510];
vector<int>a[510],t[510];
vector<pii>g[510];
bool vis[510];
int ljb[5100][5010],dis[510];
void solve(){
    cin>>n>>m>>d>>q;
    memset(ljb,0x3f,sizeof ljb);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
        for(int i=0;i<n;i++){
            cin>>k[i];
            for(int j=0;j<k[i];j++){
                int x,y;
                cin>>x>>y;
                a[i].pb(x);
                t[i].pb(y);
            }
            for(int j=0;j<k[i];j++){
                for(int l=0;l<k[i];l++){
                    if(j==l)continue;
                    ljb[a[i][j]][a[i][l]]=min(ljb[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
                    ljb[a[i][l]][a[i][j]]=ljb[a[i][j]][a[i][l]];
                }
            }
        }
        for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    for(int k=1;k<=m;k++){
                            if(i==j||j==k||i==k)continue;
                        if(ljb[i][j]+ljb[j][k]<ljb[i][k]){
                            ljb[i][k]=ljb[i][j]+ljb[j][k];
                        }
                    }
                }
            }
        while(q--){
                int x,y;
        cin>>x>>y;
        //memset(dis,0x3f,sizeof dis);
        //dis[x]=0;

            //for(int i=1;i<=m;i++){
            //    for(int j=1;j<=m;j++){
             //       cout<<ljb[i][j]<<' ';
             //   }
            //    cout<<endl;
            //}
            cout<<ljb[x][y]+w[x]+w[y]<<endl;
        }
}
/*
500
500
250000
floyd???
*/

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    //freopen("subway4.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int t=1;
    cin>>c;
    while(t--){
        solve();
    }
}
/*
subway4 corr but tle
8*4=32
32+8=40
50
remain 1h
add oil!
481*481*481
9*4=36
36+8=44
154
*/
