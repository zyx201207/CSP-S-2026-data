#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,d;
int w[500005];
int a[505][25];
int t[500005][25];
int k[505];
int s,T;
struct node{
    int y,ki;
};
vector<node>G[500005];
vector<int>p[500005];
bool v[500005];
int ans=INT_MAX;
void dfs(int x,int sum,int ki){
    //cout<<x<<' ';
    v[x]=1;
    if(x==T){
        ans=min(ans,sum+w[s]+w[T]+t[T][ki]);
        return ;
    }

    for(auto y:G[x]){
        if(v[y.y])continue;
//        v[y.y]=1;
        if(ki==y.ki)dfs(y.y,sum,ki);
        else dfs(y.y,sum+t[x][ki]+t[x][y.ki],y.ki);
        v[y.y]=0;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){

            cin>>a[i][j]>>t[a[i][j]][i];
            if(j>1){
                G[a[i][j]].push_back({a[i][j-1],i});
                G[a[i][j-1]].push_back({a[i][j],i});
            }
            p[a[i][j]].push_back(i);
        }
    }

    while(q--){
            memset(v,0,sizeof v);
        ans=INT_MAX;
        cin>>s>>T;
        for(auto it:p[s]){
            dfs(s,t[s][it],it);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
