#include<bits/stdc++.h>
using namespace std;
int ww[500010];
int dis[2020][2020];
int t[2020][2020];
int a[2020][2020];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i)
    {
        cin>>ww[i];
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;++i)
    {
        int k;
        cin>>k;
        int last=0;
        for(int j=1;j<=k;++j)
        {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k;++j)
        {
            for(int bb=j+1;bb<=k;++bb)
            {
                dis[a[i][j]][a[i][bb]]=dis[a[i][bb]][a[i][j]]=t[i][j]+t[i][bb];
            }
        }
    }
    for(int k=1;k<=m;++k)
    {
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--)
    {

        int st,ed;
        cin>>st>>ed;
        cout<<dis[st][ed]+ww[st]+ww[ed]<<endl;
    }
    return 0;
}
