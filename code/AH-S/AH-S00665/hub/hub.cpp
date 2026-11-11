#include<iostream>
#include<cstdio>
#include<vector>
#define int long long
using namespace std;
int c,t,n,k;
struct st{
    int pos,u;
};
vector<st> g[1000005];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1,u,v;i<=n-1;i++){
            cin>>u>>v;
            g[u].push_back({v,1});
            g[v].push_back({u,1});
        }
        cout<<i<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
