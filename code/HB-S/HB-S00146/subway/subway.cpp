#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long cnt,ans=1e18,ans1;
int w[500010],a[510][500010],t[510][500010],r[100010][10],k[510];
struct edge
{
    int u,v,info;
}e[1000010];
vector<int> z[500010];
bool vis[500010];
void dfs(int op,int ed)
{
    if(op==ed)
    {
        ans=min(ans,ans1);
        return;
    }
    for(int i=0;i<z[op].size();i++)
    {
        int pt=e[z[op][i]].v;
        if(!vis[pt])
        {
            vis[pt]=true;
            ans1+=e[z[op][i]].info;
            dfs(pt,ed);
            vis[pt]=false;
            ans1-=e[z[op][i]].info;
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++) cin>>r[i][0]>>r[i][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            for(int k1=j+1;k1<=k[i];k1++)
            {
                e[++cnt].u=a[i][j];
                e[cnt].v=a[i][k1];
                e[cnt].info=t[i][j]+t[i][k1];
                z[a[i][j]].push_back(cnt);
                e[++cnt].v=a[i][j];
                e[cnt].u=a[i][k1];
                e[cnt].info=t[i][j]+t[i][k1];
                z[a[i][k1]].push_back(cnt);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        vis[r[i][0]]=1;
        ans1=w[r[i][0]];
        ans=1e18;
        dfs(r[i][0],r[i][1]);
        cout<<ans+w[r[i][1]]<<endl;
        vis[r[i][0]]=0;
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*zrc*/
