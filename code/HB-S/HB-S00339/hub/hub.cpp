#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,k,u,v;
vector<int>g[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int e=1;e<-t;e++){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    return 0;
}
