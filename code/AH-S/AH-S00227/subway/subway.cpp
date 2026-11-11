#include<bits/stdc++.h>
using namespace std;
int c,n,m,k,d,q,ed,ans;
int w[500005],a,t;
bool vis[500005];
struct node{
    int id,w;
};
vector<node> v[1005];
void dfs(int x,int tm){
    if(x==ed){
    ans=min(ans,tm);
    return;
    }
    for(int i=0;i<v[x].size();i++){
        node p=v[x][i];
        if(!vis[p.id]){
            vis[p.id]=true;
            dfs(p.id,tm+p.w);
            vis[p.id]=false;
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        if(c>=7&&c<=11){
            int a1,t1;
            scanf("%d%d%d%d",&a,&t,&a1,&t1);
            v[a1].push_back({a,t+t1});
            v[a].push_back({a1,t+t1});
        }
    }
    if(c>=7&&c<=11){
        while(q--){
            int x,y;
            cin>>x>>y;
            ed=y;
            vis[x]=true;
            ans=0x3f3f3f3f;
            dfs(x,0);
            printf("%d\n",ans+w[x]+w[y]);
            vis[x]=false;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
