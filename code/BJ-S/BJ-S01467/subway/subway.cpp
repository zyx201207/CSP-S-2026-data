#include<bits/stdc++.h>
using namespace std;
int w[1000005];
int k[1000005];
vector<vector<int>>a;
vector<vector<int>>t;
int tong[1000005];
vector<vector<int>>line;
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
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            tong[a[i][j]]++;
            line[i].push_back(a[i][j]);
        }
    }
    for(int o=0;o<q;o++)
    {
        int x,y;
        cin>>x>>y;
        long long ans=w[x]+w[y];
        int linex,liney;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==x)
                {
                    ans+=t[i][j];
                    linex=i;
                }
                if(a[i][j]==y)
                {
                    ans+=t[i][j];
                    liney=i;
                }
            }
        }
        if(linex==liney)
        {
            cout<<ans<<"\n";
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            if(tong[i]>=2)
            {
                for(int ii=1;ii<=liney;ii++)
                {
                    for(int jj=1;jj<=k[i];jj++)
                    {
                        if(a[ii][jj]==i)
                        {
                            ans+=t[ii][jj];
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}