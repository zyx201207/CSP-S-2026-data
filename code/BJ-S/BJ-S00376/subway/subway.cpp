
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int x,y;
int w[5001];
int k[5001];
int a[5001][5001],t[5001][5001];
bool have[5001][5001];
int ans;
void f(int now,vector<int> vis,int timen){
    if(now==y){
        ans=max(ans,timen);
        return ;
    }
    for(int i=0;i<vis.size();i++){
        if(vis[i]==now){
            return;
        }
    }
    vis.push_back(now);
    for(int i=1;i<=n;i++){
        if(have[now][i]) continue;
        for(int j=1;j<=k[i];j++){
            if(a[i][j]==now) continue;
            f(a[i][j],vis,timen+t[i][now]+t[i][a[i][j]]);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];

    }

    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            have[a[i][j]][i]=true;
        }
    }
    for(int i=0;i<p;i++){
        cin>>x>>y;
        ans=INT_MAX;
        f(x,{},w[x]+w[y]);
        cout<<ans<<endl;
    }
}
