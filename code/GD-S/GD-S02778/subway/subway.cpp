#include<bits/stdc++.h>
using namespace std;
int minn = 1e9,x,y,w[25],k[25];
vector<pair<int,int>> e[500005];
int dfs(int s,int sum){
    if(s==y) {minn = min(max(1,minn),sum);return 0;}
    for(auto p:e[s]) sum = min(dfs(p.first,w[s]+sum),dfs(p.first,sum+p.second));
    return sum;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>k[i];
        int last_t = 0;
        for(int j = 1;j<=k[i];j++){
            int a,t;
            cin>>a>>t;
            e[i].push_back(make_pair(a,t+last_t));
            last_t = t;
        }
    }
    while(q--) {minn = 1e9;cin>>x>>y;dfs(x,0);cout<<minn<<"\n";}
    return 0;
}
