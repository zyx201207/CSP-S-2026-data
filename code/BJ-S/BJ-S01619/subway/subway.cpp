#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int w,t[40];
}a[100007];
int x[100007];
int y[100007];
int g[100007];
int c,n,m,d,q,minn;
void dfs(int nx,int goal,int p,int nline)
{
    if(nx==goal)
    {
        minn=min(minn,p+a[nx].t[nline]);
        //cout<<p+a[nx].t[nline]<<" final"<<endl<<endl;
        return;
    }
    for(int i=1;i<=min(n,d);i++)
    {
        if(a[nx].t[i]==0)
            continue;
        for(int j=1;j<=m;j++)
        {
            if(a[j].t[i]==0)
                continue;
            if(g[j]==1)
                continue;
            int np=p;
            if(nline==0)
                np+=a[nx].t[i];
            else if(i!=nline)
                np+=a[nx].t[i]+a[nx].t[nline];
            //cout<<"nx"<<nx<<" j"<<j<<" p"<<np<<"   i"<<i<<" nline"<<nline<<endl;
            g[j]=1;
            dfs(j,goal,np,i);
            g[j]=0;
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        int k,x;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x;
            cin>>a[x].t[i];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int ik=1;ik<=q;ik++)
    {
        int sum=0;
        sum+=a[x[ik]].w;
        sum+=a[y[ik]].w;
        minn=2e9;
        g[x[ik]]=1;
        dfs(x[ik],y[ik],0,0);
        g[x[ik]]=0;
        sum+=minn;
        cout<<sum<<endl;
    }
    return 0;
}
