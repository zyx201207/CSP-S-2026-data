#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5,N=505,D=25,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[M],len[M];
int e[N];
int s[M][D],t[M][D];
int dis[N][N];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        cin>>e[i];
        for(int j=1;j<=e[i];j++){
            int a,tim;
            cin>>a>>tim;
            s[a][++len[a]]=i;
            t[a][len[a]]=tim;
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=len[k];i++){
            for(int j=i+1;j<=len[k];j++){
                dis[s[k][i]][s[k][j]]=min(dis[s[k][i]][s[k][j]],t[k][i]+t[k][j]);
                dis[s[k][j]][s[k][i]]=min(dis[s[k][j]][s[k][i]],t[k][i]+t[k][j]);
            }
        }
    }
    floyd();
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=INF;
        for(int i=1;i<=len[x];i++){
            for(int j=1;j<=len[y];j++){
                ans=min(ans,w[x]+w[y]+t[x][i]+t[y][j]+dis[s[x][i]][s[y][j]]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}


