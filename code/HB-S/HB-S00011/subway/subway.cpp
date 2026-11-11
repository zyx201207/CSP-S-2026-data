#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005];
int k[100005];
int t[100005][555];
int a[555][100005];
vector<pair<int,int>>E[100005];
int dfs(int x,int y,int m){
    if(x==y){
        return m;
    }
    for(auto h:E[x]){
        m=min(dfs(h.first,y,m+h.second),m);
    }
    return m;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];

    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[j][i];
            E[a[i][j-1]].push_back({a[i][j],0});
            E[a[i-1][j]].push_back({a[i][j],2*t[j][i]});
            E[a[i][j]].push_back({a[i-1][j],2*t[j][i]});
        }

    }
    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y,100000000);
    }
    return 0;
}
