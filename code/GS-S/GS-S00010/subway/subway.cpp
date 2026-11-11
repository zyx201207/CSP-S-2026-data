#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,q,w[500005],k,a,x,y;
long long t,d[500505];
bool b[500505];
vector<pair<int,long long>> e[500505];
void D(int S){
    memset(d,0x7f,sizeof(d));d[S]=0;memset(b,0,sizeof(b));
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    q.push({0,S});
    while(q.size()){
        auto [l,u]=q.top();q.pop();
        if(b[u])continue;
        b[u]=1;
        for(auto [v,w]:e[u])if(d[v]>d[u]+w)q.push({d[v]=d[u]+w,v});
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&dd,&q);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){scanf("%d%lld",&a,&t);e[m+i].push_back({a,t});e[a].push_back({m+i,t});};
    }
    while(q--){
        scanf("%d%d",&x,&y);D(x);
        printf("%lld\n",d[y]+w[x]+w[y]);
    }
    return 0;
}
