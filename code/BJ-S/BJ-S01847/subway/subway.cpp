#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct node{
    int to,t;
};
const int N=510;
const int M=5e5+10;
long long c,n,m,d,q,w[M],vis[M],cnt[M],num;
long long dis[N][N];
long long ans;
vector<node> v[N];
vector<node> u[M];
int fr(){
    int x;
    char ch=getchar();
    while(ch>'9' || ch<'0'){
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int kl;
        cin >> kl;
        for(int j=1;j<=kl;j++){
            node g;
            cin >> g.to >> g.t;
            v[i].push_back(g);
            node gg;
            gg.to=i;
            gg.t=g.t;
            u[g.to].push_back(gg);
        }
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=0;j<u[i].size();j++){
    //         cout << i << ' ' << u[i][j].to << ' ' << u[i][j].t << "\n";
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long l=1000000000000000000;
            if(i==j) dis[i][j]=0;
            memset(cnt,0,sizeof(cnt));
            memset(vis,0,sizeof(vis));
            num=0;
            int len=v[i].size();
            for(int k=0;k<len;k++){
                vis[v[i][k].to]=v[i][k].t;
                //cout << v[i][j].t << ' ';
            }
           // cout << len << ' ';
            len=v[j].size();
            //cout << len << "\n";
            for(int k=0;k<len;k++){
                if(!vis[v[j][k].to]) continue;
                l=min(l,1ll*vis[v[j][k].to]+v[j][k].t);
               // cout << vis[v[j][k].to] << ' ' << v[j][k].t << "\n";
            }
            dis[i][j]=l;
            dis[j][i]=l;
           // cout << i << ' ' << j << ' ' << l << "\n";
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout << dis[i][j] << ' ';
    //     cout << "\n";
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++)
    //         cout << dis[i][j] << ' ';
    //     cout << "\n";
    // }
    while(q--){
        ans=1000000000000000000;
        int x,y;
        cin >> x >> y;
        int lx=u[x].size();
        int ly=u[y].size();
        for(int i=0;i<lx;i++){
            for(int j=0;j<ly;j++){
                ans=min(ans,dis[u[x][i].to][u[y][j].to]+u[x][i].t+u[y][j].t);
               // cout << x << ' '  << y << ' ' << u[x][i].to << ' ' << u[x][i].t << ' ' << u[y][j].to << ' ' << u[y][j].t << "\n";
            }
        }
        cout << ans+w[x]+w[y] << "\n";
    }
}