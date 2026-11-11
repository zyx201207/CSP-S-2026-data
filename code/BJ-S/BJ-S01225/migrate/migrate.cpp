#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll c,t,n,d,ans;
ll a[2000002],vis[2000002],dis[2000002];
bool v[5005][5005];
void dfs(int x,int f){
    if(x>n)return;
    for(int y=x+1;a[y]-a[x]<=d&&y<=n;y++){
        if(dis[y]==f)vis[y]++;
        else if(dis[y]>f)
            dis[y]=f,vis[y]=1,v[y][f]=true;
        else if(v[y][f])continue;
        dfs(y,f+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            memset(dis,0x3f,sizeof(dis));
            dfs(i,1);
            for(int j=i;j<=n;j++)
                if(vis[j]==2)ans++;
        }
        printf("%lld\n",ans);
    }
}