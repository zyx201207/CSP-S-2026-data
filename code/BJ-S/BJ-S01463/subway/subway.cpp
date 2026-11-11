#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
long long c,n,m,d,q,mn;
long long w[N],k[N];
vector<pair<int,int>> ed[N];
pair<int,int> b[N];
//za jin nian kao spafa?
//I know zhat 3 3 15 like Cristmas Day /n
bool vis[N];
void dfs(int x,int y,long long bu){
    if(x==y){
        if(bu<mn)mn=bu;
        return;
    }
    vis[x]=1;
    for(auto &e:ed[x]){
        if(vis[e.first]==0)dfs(e.first,y,bu+e.second);
    }
    vis[x]=0;
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
        int x,xw,y,yw;
        cin>>x>>xw>>y>>yw;
        ed[x].push_back({y,xw+yw});
        ed[y].push_back({x,xw+yw});
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;mn=1000000000000;
        for(int j=1;j<2*N;j++){
            vis[j]=0;
        }
        dfs(x,y,0);
        cout<<mn+w[x]+w[y];
    }
    return 0;
}

