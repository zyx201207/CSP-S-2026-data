#include<bits/stdc++.h>
#define maxn 16005
#define int long long
using namespace std;
const int INF=2147483647;
int c,n,m,d,Q,s,e;
int a[maxn],t[maxn],w[maxn];
int dis[maxn][maxn];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        int d,a1,t1,a2,t2;
        cin>>d;
        for(int j=1;j<=d;j++){
            cin>>a[j]>>t[j];
        }
        for(int j=1;j<d;j++){
            int u=a[j];
            for(int k=j+1;k<=d;k++){
                int v=a[k],ww=t[j]+t[k];
                dis[u][v]=ww;
                dis[v][u]=ww;
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(Q--){
        int s,e;
        cin>>s>>e;
        cout<<w[s]+dis[s][e]+w[e]<<"\n";
    }
}
