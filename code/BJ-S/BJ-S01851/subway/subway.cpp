#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500005];
long long t[505][500005];
bool vis[500005];
vector<int> a[505];
vector<int> line[500005];
long long ans=1e18;
long long f[20005][20005];
void dfs(int u,int v,int sum,int l){
    if(u==v){
        ans=min(sum+w[v],ans);
        return ;
    }

    for(int i=0;i<line[u].size();i++){
        if(line[u][i]==l){
            for(int j=0;j<a[line[u][i]].size();j++){
            vis[a[line[u][i]][j]]=1;
            dfs(a[line[u][i]][j],v,sum+t[l][a[line[u][i]][j]],l);
            vis[a[line[u][i]][i]]=0;
        }
    }
        else{
            long long carry=t[l][u];
            for(int j=0;j<a[line[u][i]].size();j++){
            vis[a[line[u][i]][j]]=1;
            dfs(a[line[u][i]][j],v,sum+t[l][a[line[u][i]][j]]+carry,line[u][i]);
            vis[a[line[u][i]][i]]=0;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<+n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            a[i].push_back(x);
            line[x].push_back(i);
            cin>>t[i][j];
            for(int r=1;r<=j;r++){
                f[r][j]=f[j][r]=t[i][j]+t[i][r];
            }
        }
    }

    while(q--){
        ans=1e18;
        int x,y;
        cin>>x>>y;
        vis[x]=1;
        for(int i=0;i<line[x].size();i++) dfs(x,y,w[x],line[x][i]);

        cout<<ans<<endl;
    }
    return 0;
}
