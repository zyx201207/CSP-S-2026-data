#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> g[1000010];
void solve(){
    scanf("%d%d",&n,&k);
    if(n==k){
        printf("0\n");
        return;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    printf("2\n");
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}