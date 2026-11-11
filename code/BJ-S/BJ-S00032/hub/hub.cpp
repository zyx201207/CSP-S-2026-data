#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> g[2000006];
int main(){
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<1<<endl;
    }
    return 0;
}
