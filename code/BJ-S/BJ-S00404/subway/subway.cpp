#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[514114];
vector<int> st[514114],su[514114],tr[514114],trt[514114];
long long ans;
void dfs(int x,int des,long long co,int e[]){
    e[x]=1;
    for(auto i:st[x]){
        for(auto j:st[des]){
            if(i==j){
                ans+=(trt[i][des]+trt[i][x]);
                return;
            }
        }
    }
    for(auto i:st[x]){

    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",w+i);
    for(int i=1;i<=n;i++){
        int t,s;
        scanf("%d",&t);
        su[i].push_back(t);
        for(int j=1;j<=su[i][0];j++){
            scanf("%d%d",&t,&s);
            su[i].push_back(t);
            st[t].push_back(i);
            trt[i].push_back(s);
            for(auto k:st[t]){
                if(k!=i) tr[i].push_back(k),tr[k].push_back(i);
            }
        }
    }
    while(q--){
        int u,v,vi[514];ans=0;
        scanf("%d%d",&u,&v);
        ans=w[u]+w[v];
        dfs(u,v,0,vi);
        printf("%lld\n",ans);
    }
    return 0;
}
