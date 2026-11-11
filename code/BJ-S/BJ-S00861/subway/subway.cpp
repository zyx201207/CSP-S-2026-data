#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qq,a[200001],p[200001][21],cp[200001],q[200001][21],e[501][501];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)e[i][j]=1e17;
        }
    }
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        while(t--){
            int x,y;
            cin>>x>>y;
            p[x][++cp[x]]=i;
            q[x][cp[x]]=y;
            for(int j=1;j<cp[x];j++){
                e[p[x][j]][i]=e[i][p[x][j]]=min(e[i][p[x][j]],y+q[x][j]);
            }
        }
    }
    if(c<16||c>19){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    e[i][j]=e[j][i]=min(e[i][j],e[i][k]+e[j][k]);
                }
            }
        }
    }
    while(qq--){
        int x,y,ans=1e17;
        cin>>x>>y;
        for(int i=1;i<=cp[x];i++){
            for(int j=1;j<=cp[y];j++){
                ans=min(ans,e[p[x][i]][p[y][j]]+q[x][i]+q[y][j]+a[x]+a[y]);
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
