#include<bits/stdc++.h>
using namespace std;
const int N=505,M=2e4+10;
vector<pair<pair<int,int>,int> >l[M];
int tr[N][M],a[M],vis[M];
int mini=1e9;
void dfs(int s,int e,int t){
    if(s==e){
        mini=min(mini,t);
        return;
    }
    vis[s]=1;
    for(auto sub:l[s]){
        int xl=t+sub.second;
        for(int i=sub.first.second;i<=tr[sub.first.first][0];i++){
            if(!vis[i]){
                dfs(i,e,xl);
                vis[i]=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",std.in);
    freopen("subway.out","w",std.out);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        cin>>tr[j][0];
        for(int i=1;i<=tr[j][0];i++){
            int b,c;
            cin>>b>>c;
            tr[j][i]=b;
            l[b].push_back({{j,i},c});
        }
    }
    while(q--){
        int s,e;
        cin>>s>>e;
        mini=1e9;
        memset(vis,0,sizeof vis);
        vis[s]=1;
        dfs(s,e,0);
        cout<<mini+a[s]+a[e]<<'\n';
    }
    return 0;
}
