#include<bits/stdc++.h>
using namespace std;
int c,t,n;
vector<int> e[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1,u,v;i<n;i++){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);e[v].push_back(u);
        }
    }
    return 0;
}
