#include<cstdio>
const int N=2e6+5;
int a[N],dfsans,dfsmin=2e9,n,d;
void dfs(int u,int Y,int dis){
    if(u==Y){
        if(dfsmin==dis) ++dfsans;
        else if(dfsmin>dis){
            dfsmin=dis;
            dfsans=1;
        }
        return;
    }
    if(u>Y) return;
    for(int i=u+1;i<=n;i++)
        if(a[i]-a[u]<=d&&i<=Y) dfs(i,Y,dis+1);
        else break;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++){
                dfsmin=2e9;
                dfsans=0;
                dfs(i,j,0);
                if(dfsans==2){
                    // printf("%d %d\n",i,j);
                    ++ans;
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}