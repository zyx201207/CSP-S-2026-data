#include <bits/stdc++.h>
using namespace std;
int num,u[100005],minn=0x3f3f3f,ss,ee,a[100005],b[100005],w[100005],g,h;
vector<pair<int,int>>e[100005];
void dfs(int st,int en)
{
    if(st==en)
    {
        minn=min(minn,num);
        return;
    }
    for(int e[st]{g,h};;)
    {
        if(u[g]==0)
        {
            num+=h;
            u[g]=1;
            dfs(g,en);
            num-=h;
            u[g]=0;
        }
        else
        {
            continue;
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[j]>>b[j];
        }
        for(int j=1;j<=k;j++)
        {
            for(int f=j+1;f<=k;f++)
            {
                e[a[j]].push_back({a[f],b[j]+b[f]});
                e[a[f]].push_back({a[j],b[j]+b[f]});
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        num=0;
        minn=0x3f3f3f;
        for(int j=1;j<=m;j++)
        {
            u[j]=0;
        }
        cin>>ss>>ee;
        dfs(ss,ee);
        cout<<minn+w[ss]+w[ee]<<endl;
    }
    return 0;
}
