#include <bits/stdc++.h>
using namespace std;
const int N = 505,M = 1005;
int c,n,m,q,d,w[M],a[N][M],t[N][M];
vector<int> g[M];
long long ans;
struct node{
    int v,id;
    long long sum=0;
    bool operator < (const node& other) const{
        return sum > other.sum;
    }
};
void bfs(int l,int r){
    priority_queue<node> q;
    for(int p:g[l]){
        int lo=0;
        for(;lo <= a[p][0];lo++)if(a[p][lo] == l)break;
        q.push({l,p,t[p][lo]});
    }
    while(!q.empty()){
        node u = q.top();
        q.pop();
        if(u.v == r){
            ans=min(ans,u.sum);
            continue;
        }
        if(u.sum > ans)continue;
        int i=1;
        for(;i<=a[u.id][0];i++){
            if(a[u.id][i] == u.v)break;
        }
        for(;i<=a[u.id][0];i++){
            if(a[u.id][i] == r){
                ans=min(ans,u.sum+1ll*t[u.id][i]);
            }
            for(int j:g[a[u.id][i]]){
                if(j != u.id){
                    int lo=1;
                    for(;lo <= a[j][0];lo++)if(a[j][lo] == a[u.id][i])break;
                    q.push({a[u.id][i],j,u.sum+1ll*t[j][lo]+1ll*t[u.id][i]});
                }
            }
        }
    }
}
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&a[i][0]);
        for(int j=1;j<=a[i][0];j++){
            scanf("%d %d",&a[i][j],&t[i][j]);
            g[a[i][j]].push_back(i);
        }
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        ans=LLONG_MAX;
        bfs(l,r);
        printf("%lld\n",ans+w[l]+w[r]);
    }

    return 0;
}
