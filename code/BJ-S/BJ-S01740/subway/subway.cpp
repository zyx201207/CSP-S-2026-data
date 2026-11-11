#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=5e2+10;
int c,n,m,d,q,ans=INT_MAX,cnt=0;
int u,v;
//n -> num(xian lu)    m -> num(zhan)
int w[M];
vector<int> x[N];// zhan de xian lu you na xie
vector<int> y[N];//xian lu jing guo na xie zhan
int t[M][N];
int vis[M];
void dfs(int s){
    if(s==v){
        ans=min(cnt,ans);
        return;
    }
    vis[s]=1;
    for(auto i:x[s]){
        for(auto j:y[i]){
            if(vis[j]==0){
                vis[j]=1;
                cnt+=t[j][i];
                dfs(j);
                vis[j]=0;
                cnt-=t[j][i];
            }
        }
    }
    vis[s]=0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,tt;
            cin>>a>>tt;
            t[a][i]=tt;
            x[a].push_back(i);
            y[i].push_back(a);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>u>>v;
        dfs(u);
        ans+=w[u];
        ans+=w[v];
        cout<<ans<<endl;
        ans=INT_MAX;
    }
    return 0;
}
