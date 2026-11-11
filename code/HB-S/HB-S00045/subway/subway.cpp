#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
    int v,t;
}a[505][N];
vector<int> e[N];
int c,n,m,d,q,w[N],k[505],ans=2e9;
bool b[N];
void dfs(int x,int en,int sum){
    if(x==en){
        ans=min(ans,sum);
        return;
    }
    for(auto y : e[x]){
        if(!b[y]){
            b[y]=true;
            for(int i=1;i<=n;i++){
                for(int j=1;j<k[i];j++){
                    if(a[i][j].v==y){
                        dfs(y,en,sum+2*a[i][j].t);
                    }
                }
            }
        }
    }
}
int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d",&c);
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j].v,&a[i][j].t);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<k[i];j++){
            e[a[i][j].v].push_back(a[i][j+1].v);
            e[a[i][j+1].v].push_back(a[i][j].v);
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        memset(b,false,sizeof(b));
        ans=2e9;
        dfs(x,y,w[x]+w[y]);
        printf("%d\n",ans);
    }

    return 0;
}
