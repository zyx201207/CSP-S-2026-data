#include<bits/stdc++.h>
using namespace std;
struct node
{
    int way,val;
}o;
vector<node> E[501];
vector<int> a[500001],t[500001];
int c,n,m,d,q,w[501],k,x,y,minn=1e9;
void dfs(int u,int v,int sum)
{
    for(int i=0;i<a[u].size();i++)
    {
        if(a[u][i]==y)
        {
            minn=min(minn,sum+t[u][i]+t[u][v]);
            return;
        }
        if(i==v) continue;
        for(int j=1;j<E[a[u][i]].size();j++)
        {
            if(E[a[u][i]][j].way==u) continue;
            for(int l=0;l<a[E[a[u][i]][j].way].size();l++)
            {
                if(a[E[a[u][i]][j].way][l]==a[u][i])
                {
                    dfs(E[a[u][i]][j].way,l,sum+t[u][i]+t[u][v]);
                    break;
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            o.way=i,o.val=y;
            E[x].push_back(o);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=n;j++)
        {
            for(int l=0;l<a[j].size();l++)
            {
                if(a[j][l]==x)
                {
                    dfs(j,l,w[x]);
                    break;
                }
            }
        }
        cout<<minn+w[y]<<endl;
        minn=1e9;
    }
    return 0;
}
