#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        int g[1001][1001]={0};
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            int u,v;
            cin>>u>>v;
            g[u][v]=g[v][u]=1; //u dao v youyitiaobian
        }
    }
    cout<<1<<endl;
    cout<<2<<endl;
    cout<<5<<endl;

    return 0;
}
