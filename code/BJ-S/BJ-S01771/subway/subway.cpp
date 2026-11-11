#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005];
int a[505][20005];
int t[505][20005];
int mp[20004][20005];
vector<int> v[20005];
int vis[20005];
long long ans,ans1;
int cnt,mixx=100000000;
void dfs(int x,int y){
    if(ans1+mixx>ans) return ;
    for(int q:v[x]){
        if(vis[q]==0){
            ans1+=mp[x][q];
            if(q==y){
                ans=ans1;
                return ;
            }
            vis[q]=1;
            dfs(q,y);
            vis[q]=0;
            ans1-=mp[x][q];
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
            if(j!=1){
                v[a[i][j]].push_back(a[i][j-1]);
                v[a[i][j-1]].push_back(a[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ans=100000000000,ans1=0;
        for(int j=1;j<=m;j++) vis[j]=0;

        vis[x]=1;
        dfs(x,y);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
