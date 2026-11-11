#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int poi[505][500005];
int cr[500120],a,t;
int biao[500120];
int dfs(int x,int y,int ci)
{
    if(ci>n*m) return 1e9;
    int jk = 1e9;
    for(int i = 1;i<=n;i++)
    {
        if(poi[i][x]!=-1 && poi[i][y]!=-1) jk = min(jk,poi[i][y]+poi[i][x]);
    }
    if(jk!=1e9)
    {
        return jk;
    }
    jk = 1e9;
    for(int s = 1;s<=n;s++)
    {
        for(int i = x;i<=y;i++)
        {
            if(biao[i]!=1 && poi[s][i]!=-1 && poi[i][y]!=-1)
            {
                biao[i] = 1;
                jk = min(jk,dfs(x,i,ci+1)+dfs(i,y,ci+1));
                biao[i] = 0;
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(int i = 1;i<=m;i++) cin>>cr[i];
    for(int i = 1;i<=n+1;i++)
    {
        for(int j = 1;j<=m+1;j++)
        {
            poi[i][j] = -1;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        int nnn;
        cin>>nnn;
        for(int j = 1;j<=nnn;j++)
        {
            cin>>a>>t;
            poi[i][a] = t;
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) cout<<0;
        else
        {
            cout<<dfs(min(x,y),max(x,y),0)+cr[x]+cr[y];
        }
        cout<<"\n";
    }
    return 0;
}
