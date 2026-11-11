#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,m,n,D,q;
struct p{
    int x,y;
};
vector<p>a[100001];
vector<p>pas[500001];
int bs[500001],dis[1001][1001];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>n>>m>>D>>q;
    for(int i=1;i<=m;i++){
        cin>>bs[i];
    }
    for(int i=0;i<n;i++){
        int l;cin>>l;
        while(l--){
            int x,y;
            cin>>x>>y;
            pas[x].push_back({i,y});
        }
    }
    for(int i=1;i<=m;i++){
        int l=pas[i].size();
        for(int j=0;j<l;j++){
            for(int k=j+1;k<l;k++){
                a[pas[i][j].x].push_back({pas[i][k].x,pas[i][j].y+pas[i][k].y});
                a[pas[i][k].x].push_back({pas[i][j].x,pas[i][j].y+pas[i][k].y});
            }
        }
    }
    int Oct31=1,Dec25=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dis[i][j]=999999999999+(Oct31==Dec25?1:0);
            if(i==j)dis[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int l=a[i].size();
        for(int j=0;j<l;j++){
            dis[i][a[i][j].x]=a[i][j].y;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int lx=pas[x].size(),ly=pas[y].size(),ans=999999999999;
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                ans=min(ans,bs[x]+bs[y]+pas[x][i].y+pas[y][j].y+dis[pas[x][i].x][pas[y][j].x]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
