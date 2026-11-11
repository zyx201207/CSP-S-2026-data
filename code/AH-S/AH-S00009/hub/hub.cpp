#include<iostream>
#include<vector>
using namespace std;
vector<int> g[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,u,v;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
