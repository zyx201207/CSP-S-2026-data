#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e6+10;
int pre[N],idx,e=INT_MAX,x[N],y[N],k[N],b[N],w[2005][2005],t[2005][2005];
int d[N];
bool f[N];
struct node{
    int to;
    int len;
    int next;
}a[N];
void add(int u,int v,int l){
    idx++;
    a[idx].to=v;
    a[idx].len=l;
    a[idx].next=pre[u];
    pre[u]=idx;
}
priority_queue<PII,vector<PII>,greater<PII>>heap;
void spfa(int r,int t){

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,le,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&le,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);//进出
    }
    for(int i=1;i<=n;i++){
        e=INT_MAX;
        for(int j=1;j<=e+1;j++){
            if(j==1){
                scanf("%d",&k[i]);
                e=2*k[i];
                continue;
            }
            int z=j;
            z=(z+1)/2;
            scanf("%d%d",&w[i][z],&t[i][z]);
        }
    }
    for(int i=1;i<=q;i++){
        cout<<"a";
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            for(int v=j+1;v<=k[i];j++){
                add(w[i][j],w[i][v],t[i][j]+t[i][v]);
                add(w[i][v],w[i][j],t[i][j]+t[i][v]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        memset(d,0x3f3f3f,sizeof(d));
        heap.push({0,x[i]});
        d[x[i]]=0;
        while(!heap.empty()){
            PII h=heap.top();
            heap.pop();
            int dis=h.first,p=h.second;
            if(f[p])continue;
            f[p]=true;
            if(p==y[i]){
                printf("%d",dis+b[y[i]]);
            }
            for(int i=pre[p];i!=0;i=a[i].next){
                int to=a[i].to;
                if(d[to]>dis+a[i].len){
                    d[to]=dis+a[i].len;
                    heap.push({d[to],to});
                }
            }
        }
    }
    return 0;
}
