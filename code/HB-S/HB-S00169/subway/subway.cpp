#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;

int c,n,m,d,q,k,a,x,y,ans,t1=INT_MAX;
int w[N],p[505][N],vis[N];

void dfs(int station,int spent,int line)
{
    if(station==y)
    {
        ans=min(ans,spent);
        return;
    }
    for(int i=1;i<=m;i++){
        if(p[line][i]&&!vis[i])
        {
            vis[i]=1;
            dfs(i,spent,line);
            vis[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=line&&p[i][station])
        {
            dfs(station,spent+p[i][station],i);
        }
    }
}

int main(void)
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a;
            cin>>p[i][a];
        }
    }

    while(q--)
    {
        cin>>x>>y;
        ans=INT_MAX;
        for(int i=1;i<=n;i++){
            if(p[n][x])
            {
                t1=min(t1,p[n][x]);
            }
        }
        dfs(x,w[x]+w[y]+t1,1);

        cout<<ans<<endl;

    }

    return 0;
}
