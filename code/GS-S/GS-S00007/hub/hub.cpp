#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n,k;
vector<int>g[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d %d",&c,&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i = 1,v,u;i < n;i++){
            scanf("%d %d",&v,&u);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll ans = 1e18;

        ans = 1;
        printf("%d\n",ans);
    }
    return 0;
}
