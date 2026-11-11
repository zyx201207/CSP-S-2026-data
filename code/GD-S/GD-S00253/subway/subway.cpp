#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+10;
const int M=110;
int n,m,d,q,w[N],k[N],a[M][N],t[N][M];
int dis[N][N];
void solve2(int x,int y){
    int ans=0;int T=t[1][1];
    ans+=w[x]+w[y]+T*2;
    // for(auto v:e)
    cout<<ans<<"\n";
}
vector<int>e[N];   
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    int flg=1;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[j][i];
            e[a[i][j]].push_back(i);
        }
        for(int j=1;j<=k[i];j++){
            for(int l=1;l<=k[i];l++)dis[a[i][j]][a[i][l]]=0,dis[a[i][l]][a[i][j]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(auto lx:e[i]){
            for(int j=1;j<=k[lx];j++){
                dis[j][i]=dis[i][j]=min(dis[i][j],t[j][lx]+t[i][lx]);
            }
        }
    }
    for(int l=1;l<=m;l++){
        for(int i=1;i<=m;i++){
            if(l==i||dis[i][l]==0x3f3f3f3f3f3f3f3f)continue;
            for(int j=1;j<=m;j++){
                if(l==j||j==i||dis[l][j]==0x3f3f3f3f3f3f3f3f)continue;
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        // if(c>=12&&c<=19)solve2(x,y);
        cout<<w[x]+w[y]+dis[x][y]<<"\n";
    }
    return 0;
}