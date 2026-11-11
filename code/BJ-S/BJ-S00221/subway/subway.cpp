#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int dfs(int s,int e,vector<vector<bool>>& vis,vector<vector<int>>& g,vector<int>& w){
    //cout<<"OK"<<endl;
    //cout<<s<<endl;
    if(g[s][e]!=-1){
            return g[s][e]+w[s];
    }
    int t=INT_MAX;
    for(int i=1;i<=m;i++){
        if(g[s][i]==-1){
            continue;
        }
        if(vis[s][i]==true){
            continue;
        }
        vis[s][i]=true;
        int val=dfs(i,e,vis,g,w);
        t=min(t,(val==INT_MAX?t:val+g[s][i]+w[i]));
    }
    return t;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int>w(m+10);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<vector<int>> g(m+10,vector<int>(m+10,-1));
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            g[i][a]=t;
        }
    }
    while(q--){
        int b,e;
        cin>>b>>e;
        vector<vector<bool>> vis(m+10,vector<bool>(m,false));
        cout<<dfs(b,e,vis,g,w)<<endl;
    }
    return 0;
}
