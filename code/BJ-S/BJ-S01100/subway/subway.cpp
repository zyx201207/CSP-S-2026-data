#include<bits/stdc++.h>
#define int long long
#define MAX 1000010
using namespace std;
struct ST{
    int x;
    int y;
};
int c,n,m,d,q;
int w[MAX];
int k[MAX];
int a[505][20005];
int t[505][20005];
vector<ST> v[500005];
int ans;
int f[505][1005][2];
void dfs(int x,int p,int e,int b,int ed,int sum){
    if(x==ed&&b==1){
        ans=min(ans,sum);
        return ;
    }
    if(f[p][e][b]==1) return ;
    f[p][e][b]=1;
    if(b==1){
        for(int i=0;i<v[x].size();i++){
            dfs(x,v[x][i].x,v[x][i].y,0,ed,sum+t[v[x][i].x][v[x][i].y]);
        }
    }else{
        dfs(x,n+x,n+x,1,ed,sum+t[p][e]);
        if(e!=1){
            if(e!=k[p]){
                dfs(a[p][e-1],p,e-1,0,ed,sum);
                dfs(a[p][e+1],p,e+1,0,ed,sum);
            }else{
                dfs(a[p][e-1],p,e-1,0,ed,sum);
            }
        }else{
            dfs(a[p][e+1],p,e+1,0,ed,sum);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            v[a[i][j]].push_back({i,j});
        }
    }
    for(int r=1;r<=q;r++){
        int x,y;cin>>x>>y;
        ans=9e18;
        memset(f,0,sizeof f);
        dfs(x,n+x,n+x,1,y,0);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
