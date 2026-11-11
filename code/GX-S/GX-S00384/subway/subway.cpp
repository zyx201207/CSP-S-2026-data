#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,a,k;
long long w[500005],map1[505][500005];
int ans,l,r;
bool vis[505][20004];
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
void f(long long d,long long z)
{

    if(z==r)
    {
        return ;
    }
    for(int i=1;i<=4;i++)
    {
        int x=dx[i]+d;
        int y=dy[i]+z;
        if(map1[x][y]!=-1 && vis[x][y]==0)
        {
            ans+=map1[x][y];
            vis[x][y]=1;
            f(x,y);

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
        cin>>w[i];
    }
    memset(map1,-1,sizeof(map1));
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a>>t;
            map1[i][a]=t;
        }

    }
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        ans=w[l]+w[r];
        f(1,l);
        cout<<ans<<endl;
    }
    return 0;
}
