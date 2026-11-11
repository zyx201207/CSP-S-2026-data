#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=5e2+10,D=2e1+10;
int c,n,m,d,z,s,q,w[M],k[N],a[N][M],t[N][M],vis[M],ans;
struct st{
    int sa,sb,sc;
};
vector<st>e[M];
void solve(int x,int y,int op,int zt){
 //  cout<<x<<' '<<y<<' '<<op<<"\n";
    if(a[x][y]==s){
        ans=min(ans,op);
        return;
    }
    if(op>=ans){
        return;
    }
    vis[a[x][y]]=1;
    if(zt==0){
        for(int i=0;i<e[a[x][y]].size();i++){
        int sa=e[a[x][y]][i].sa,sb=e[a[x][y]][i].sb,sc=e[a[x][y]][i].sc;
        if(!vis[a[sa][sb+1]]&&sb+1<=k[sa]){
            solve(sa,sb+1,op+sc,1);
        }
        else if(!vis[a[sa][sb-1]]&&sb-1>=1){
            solve(sa,sb-1,op+sc,1);
        }
    }
    if(zt==1){
        if(y+1<=k[x]&&!vis[a[x][y+1]])
        solve(x,y+1,op,1);
    if(y-1>=1&&!vis[a[x][y-1]])
        solve(x,y-1,op,1);
    for(int i=0;i<e[a[x][y]].size();i++){
        int sa=e[a[x][y]][i].sa,sb=e[a[x][y]][i].sb,sc=e[a[x][y]][i].sc;
        if(sa==x)continue;
        if(!vis[a[sa][sb+1]]&&sb+1<=k[sa]){
            solve(sa,sb+1,op+t[x][y]+sc,1);
        }
        else if(!vis[a[sa][sb-1]]&&sb-1>=1){
            solve(sa,sb-1,op+t[x][y]+sc,1);
        }
    }
    }
    vis[a[x][y]]=0;
}
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            e[a[i][j]].push_back({i,j,t[i][j]});
        }
    }
    for(int i=1;i<=q;i++){
        ans=0x3f;
        memset(vis,0,sizeof(vis));
        cin>>z>>s;
        solve(e[z][0].sa,e[z][0].sb,0,0);//opopopop
        cout<<w[z]+w[s]+ans<<"\n";
    }
    return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2*/
