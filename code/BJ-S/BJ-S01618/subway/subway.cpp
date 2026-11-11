#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> e[5005];
int n,m,q,c,dd,tot=0,cnt=0;int kou[5005],ting[5005],tai[5005],mp[5005];long long inf=1e15;
struct node{
    long long d[3005],v[3005];
//    node(){
//        for (int i=1;i<=tot;i++){
//            d[i]=inf;v[i]=0;
//        }
//    }
};
node d[3005];
void dijkstra(int i,int a){
    priority_queue<pair<long long,int>> q;
    for (int j=1;j<=tot;j++) d[i].d[j]=inf;d[i].d[a]=0;
    q.push({0,a});
    while (!q.empty()){
        pair<long long,int> p=q.top();
        q.pop();
        long long u=p.second;
        if (d[i].v[u]){
            continue;
        }
        d[i].v[u]=1;
        for (pair<int,long long> p:e[u]){
            int v=p.first;long long w=p.second;
            if (d[i].d[v]>d[i].d[u]+w){
                d[i].d[v]=d[i].d[u]+w;
                q.push({-d[i].d[v],v});
            }
        }
    }
}
//void spfa(int i,int a){
//    queue<int> q;
//    d[i].d[a]=0;
//    q.push(a);d[i].v[a]=1;
//    while (!q.empty()){
//        int u=q.front();
//        q.pop();d[i].v[u]=0;
//        for (pair<int,long long> p:e[u]){
//            int v=p.first;long long w=p.second;
//            if (d[i].d[v]>d[i].d[u]+w){
//                d[i].d[v]=d[i].d[u]+w;
//                if (!d[i].v[v]){
//                    q.push(v);
//                    d[i].v[v]=1;
//                }
//            }
//        }
//    }
//}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&dd,&q);
    for (int i=1;i<=m;i++){
        long long t;//walk to zhanting
        scanf("%lld",&t);
        kou[i]=++tot;ting[i]=++tot;
        e[kou[i]].push_back({ting[i],t});
        e[ting[i]].push_back({kou[i],t});
    }
    for (int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);++tot;
        for (int j=1;j<=k;j++){
            long long a,t;
            scanf("%d%lld",&a,&t);
            e[tot].push_back({ting[a],t});
            e[ting[a]].push_back({tot,t});
        }
    }
    for (int i=1;i<=tot;i++){
        dijkstra(i,i);
    }
    for (int i=1;i<=q;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        //printf("%d %d\n",a[u],a[v]);
        printf("%lld",d[kou[u]].d[kou[v]]);if (i!=q)printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
