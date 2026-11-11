
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
int w[500005];
int a[500005][500005],t[500005][500005];
int k[505];
vector<int> g[505];
int dfs(int x,int y){
    if(g[x]==y){
        return ;
    }
    dfs(g[x],y);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            g[a[i][j]].push_back(a[i][j+1]);
            g[a[i][j+1]].push_back(a[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        cout<<(x+y)*9;
    }
    return 0;
}
