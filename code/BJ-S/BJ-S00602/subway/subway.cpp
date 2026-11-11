#include<iostream>
using namespace std;
int w[500005],a[505][25],t[505][25],sw[500005],v[500005];
int c,n,m,d,q;
int x,y;
int ans=100000000;
void dfs(int nw,int tnw,int lnw)
{
    if(nw==y)//jie suan mvp
    {
        tnw+=w[y]+t[lnw][y];
        ans=min(ans,tnw);
        return ;
    }
    for(int i=1;i<=d;i++)//bu huan
    {
        if(v[a[lnw][i]]==0)
        {
            v[a[lnw][i]]=1;
            dfs(a[lnw][i],tnw,lnw);
            v[a[lnw][i]]=0;
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
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
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
        }
    }
    while(q--)
    {
        cin>>x>>y;
        for(int i=1;i<=n;i++)
        {
            v[x]=1;
            dfs(x,w[x]+t[i][x],i);
            v[x]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//zhe sha po jian pan - he = de jian dou shi fan zhe de
//xie zhe - da chu lai shi = , xie zhe = da chu lai shi -
//wbxl
//rdfz ni huan dian she bei ba wo qiu ni le
//shift kong ge sha de dou an bu xia qu....
