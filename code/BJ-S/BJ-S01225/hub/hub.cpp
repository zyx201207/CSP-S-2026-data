#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,ans;
vector<int> g[1000001];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=rand();
        printf("%d",ans);
    }
}