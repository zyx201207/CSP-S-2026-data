#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxn=2000001;
vector<bool> vis(maxn,false);
vector<int> pos(maxn,0);
vector<vector<int>> st(maxn,vector<int>(maxn,1e6)),cnt(maxn,vector<int>(maxn,0));
int n,d;
void dfs(int dep,int t,int s){
    vis[t]=true;
    if(dep<st[s][t]){
        cnt[s][t]=1;
        st[s][t]=dep;
    }
    else if(dep==st[s][t]){
        cnt[s][t]++;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!(vis[i]||abs(pos[t]-pos[i])>d)){
                dfs(dep+1,i,s);
            }
        }
    }
    vis[t]=false;
}
void init(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        vis[i]=false;
        for(int j=1;j<=n;j++){
            st[i][j]=1e6;
            cnt[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        dfs(0,i,i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(cnt[i][j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        init();
    }
    return 0;
}
