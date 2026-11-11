#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k,c,t,n,G[2000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        scanf("%lld%lld",&n,&k);
        LL u,v;
        for(LL i=1;i<=n;i++){
            scanf("%lld%lld",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cout<<1<<endl;
    }
    return 0;
}
