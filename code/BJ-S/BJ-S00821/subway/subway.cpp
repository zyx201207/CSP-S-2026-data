#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,re;
int w[500010],k[500010],a[50010][510],t[50010][510];
int x[100010],y[100010];
struct p{
    int in,step,cnt,line;
};
bool vis[50010][21];
vector<int> path;
void dfs(int in,int en,int step,int cnt,int line){
    path.push_back(in);
    if(in==en){
        re=min(re,cnt+t[line][step]);
        return;
    }
    vis[line][step]=true;
    //huancheng
    for(int i=1;i<=n;i++){
        if(i==line){
            continue;
        }
        for(int j=1;j<=k[i];j++){
            if(vis[i][j]){
                continue;
            }
            if(a[i][j]==in){
                dfs(a[i][j],en,j,cnt+t[line][step]+t[i][j],i);
            }
        }
    }
    //jixu
    if(a[line][step+1]!=0&&vis[line][step+1]==false){
        dfs(a[line][step+1],en,step+1,cnt,line);
    }
    if(a[line][step-1]!=0&&vis[line][step-1]==false){
        dfs(a[line][step-1],en,step-1,cnt,line);
    }
    vis[line][step]=false;
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int k_=1;k_<=q;k_++){
        re=1e10;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x[k_]){
                    dfs(x[k_],y[k_],j,t[i][j],i);
                }
            }
        }
        cout<<re+w[x[k_]]+w[y[k_]]<<endl;
    }
    return 0;
}
