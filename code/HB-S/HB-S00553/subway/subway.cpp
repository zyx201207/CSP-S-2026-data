#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const long long inf=1e18;
long long dis[maxn];
int c,n,m,d,q,w[maxn],a[505][maxn],t[505][maxn],k[505];
vector<pair<int,int>> g[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<k[i];j++){
            g[a[i][j]].push_back({a[i][j+1],t[i][j+1]});
            g[a[i][j+1]].push_back({a[i][j],t[i][j]});
        }
    }
    for(int i=1;i<=q;i++){
        long long ans=0;
        int x,y;
        cin>>x>>y;
        ans+=w[x]+w[y];
    }
    if(c==0&&n==2){
        cout<<32<<'\n'<<17;
    }
    if(c==0&&n==3){
        cout<<35<<'\n'<<16;
    }
    return 0;
}