#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
const int INF=1e9;
int C,Q;
int n,d;

int dfs(int ans,int st,int fi,int cnt,const vector<vector<int>> &g){
    for(int v:g[st]){
        cnt++;
        if(v==fi){
            return min(ans,cnt);
        }
        dfs(ans,v,fi,cnt,g);
    }
}
int cnt=0;
void dfs2(int left,int st,int fin,const vector<vector<int>> &g){
    for(int v:g[st]){
        left--;
        if(left<0) return;
        else if(left==0&&v==fin){cnt++;}
        dfs2(left,v,fin,g);
    }
}
void solve(){
    int ans=0;
    cin>>n>>d;
    vector<int> pos(n+1,0);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;i++){
        cin>>pos[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dis=pos[j]-pos[i];
            if(dis>d) continue;
            g[i].push_back(j);
        }
    }
    int mindis=1e9;
    for(int st=1;st<=n;st++){
        for(int fi=st+2;fi<=n;fi++){
            cnt=0;
            mindis=dfs(INF,st,fi,0,g);
            dfs2(mindis,st,fi,g);
            if(cnt==2) ans++;
        }
    }
    cout<<ans-1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>Q;
    while(Q--){
        solve();
    }
    return 0;
}
