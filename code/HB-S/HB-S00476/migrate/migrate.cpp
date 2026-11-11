#include <bits/stdc++.h>
using namespace std;
/*typedef long long LL;
typedef pair<int,int> PII;
const int N=5500;
int c,n,d,t;
LL a[N];
int sum[N][N];
struct Edge{
    int to,w,next;
}edge[N];
int head[N],num;
void add(int u,int v,int w){
    num++;
    edge[num].to=v;
    edge[num].w=w;
    edge[num].next=head[u];
    head[u]=num;
}
LL dis[N][N];
bool vis[N];
void dijk(int u){
    priority_queue<PII,vector<PII>,greater<PII>> q;//small to big
    dis[u][u]=0;
    q.push({0,u});
    while(!q.empty()){
        PII cmp=q.top();
        int z=cmp.second;
        q.pop();
        if(vis[z]) continue;
        vis[z]=1;
        for(int j=head[z];j;j=edge[j].next){
            int v=edge[j].to;
            if(dis[u][v]>dis[u][z]+edge[j].w){
                dis[u][v]=dis[u][z]+edge[j].w;
                q.push({dis[u][v],v});
            }
        }
    }
}
void dijk_2(int u){
    priority_queue<PII,vector<PII>,greater<PII>> q;//small to big
    dis[u][u]=0;
    q.push({0,u});
    while(!q.empty()){
        PII cmp=q.top();
        int z=cmp.second;
        q.pop();
        if(vis[z]) continue;
        vis[z]=1;
        for(int j=head[z];j;j=edge[j].next){
            int v=edge[j].to;
            if(dis[u][v]==dis[u][z]+1){
                sum[u][v]++;
                q.push({dis[u][v],v});
            }
        }
    }
}*/
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    /*scanf("%d%d",&c,&t);
while(t){
    t--;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=INT_MAX;
            if(a[j]-a[i]<=d){
                printf("%d %d\n",i,j);
                add(i,j,1);
                add(j,i,1);
            }else{
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        dijk(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            printf("%d ",dis[i][j]);
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        dijk_2(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            printf("%d ",sum[i][j]);
        }
        cout<<endl;
    }
*/
    return 0;
}

