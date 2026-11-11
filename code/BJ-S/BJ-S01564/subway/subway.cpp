#include <bits/stdc++.h>
using namespace std;
struct couple{
    int b1;
    long long b2;
}u,v;
int c,m,n,d,Q;
int w[500005],k[505];
int a[505][500005];
int t[505][500005];
int be,en;
vector<couple> stop[500005];
vector<couple> line[505];
queue<couple> q;
long long vis[505],mini;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&m,&n,&d,&Q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            scanf("%d %d",&a[i][j],&t[i][j]);
            u.b1=i,u.b2=t[i][j];
            stop[a[i][j]].push_back(u);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            for(auto x:stop[a[i][j]])
            {
                if(x.b1==i)continue;
                u.b1=x.b1,u.b2=x.b2+t[i][j];
                line[i].push_back(u);
            }
        }
    }
    for(int i=1;i<=Q;i++)
    {
        scanf("%d %d",&be,&en);
        mini=1e18;
        for(auto x:stop[be])
        {
            u.b1=x.b1,u.b2=x.b2+w[be];
            q.push(u);
        }
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(auto x:stop[en])
            {
                if(x.b1==u.b1)
                {
                    mini=min(u.b2+x.b2+w[en],mini);
                    break;
                }
            }
            if(vis[u.b1])
            {
                vis[u.b1]=min(vis[u.b1],u.b2);
            }
            else
            {
                vis[u.b1]=u.b2;
            }
            for(auto x:line[u.b1])
            {
                if(!vis[x.b1])
                {
                    v.b1=x.b1,v.b2=u.b2+x.b2;
                    q.push(v);
                }
            }
        }
        printf("%lld\n",mini);
    }
    return 0;
}