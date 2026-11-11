#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
const int M = 5e5+5;
int w[M];
vector<int> a[N];
int t[M][N];
vector<int> dd[M];
vector<pair<int,int> > xy;
bool vis[M];
ll dfs(int pos,int posy){
    if(vis[pos]) return LONG_MAX/2;
    vis[pos]=1;
    ll time=LONG_MAX;
    for(auto i:dd[pos]){
        for(auto j:a[i]){
            //if(!vis[j]) cout<<pos<<" "<<i<<" "<<t[pos][i]<<endl<<
                              //pos<<" "<<j<<" "<<t[j][pos+1]<<endl;
            if(j==posy){
                time=t[pos][i]+t[j][pos+1];
                return time;
            }
            time=min(time,t[pos][i]+t[j][pos+1]+dfs(j,posy));
            vis[j]=0;
        }
    }
    return time;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int aa;cin>>aa;
            a[j].push_back(aa);
            dd[aa].push_back(j);
            int tt;cin>>tt;
            t[aa][j]=tt;

        }
    }
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        xy.push_back({x,y});
    }
    for(auto ij:xy){
        int i=ij.first,j=ij.second;
        cout<<w[i]+dfs(i,j)+w[j]<<endl;
    }
    return 0;
}
