#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,sta[510],dp[501],bj[510];
struct node{
    int to,len;
};
vector<node> e[510];
int bfs(int u){
    queue<int> p;
    dp[u]=0;
    p.push(u);
    bj[u]=1;
    while(p.size()){
        int t=p.front();
        p.pop();
        bj[t]=0;
        for(int i=0;i<e[t].size();i++){
            int to=e[t][i].to,len=e[t][i].len;
            if(dp[to]>dp[t]+len) dp[to]=dp[t]+len;
            else continue;
            if(bj[to]) continue;
            p.push(to);
            bj[to]=1;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>sta[i];
    }for(int i=1,k,f,l,t2,t1;i<=n;i++){
        scanf("%d%d%d%d%d",&k,&f,&t1,&l,&t2);
        e[f].push_back({l,(t1+t2)});
        e[l].push_back({f,(t1+t2)});
    }while(q--){
        int from,to;
        memset(dp,0x3f,sizeof dp);
        memset(bj,0,sizeof bj);
        cin>>from>>to;
        bfs(from);
        dp[to]+=(sta[from]+sta[to]);
        printf("%d\n",dp[to]);
    }
    return 0;
}
