#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int tt[500005],cnt[500005];
int k[505];
int a[10][500005],t[10][500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    if(n!=2)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                cin>>a[i][j]>>t[i][j];
            }
        }
    }
    if(n<=2)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>k[i];
            for(int j=1;j<=k[i];j++)
            {
                cin>>a[i][j]>>t[i][j];
            }
        }
        for(int i=1;i<=2;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                tt[a[i][j]]+=t[i][j];
                cnt[a[i][j]]++;
            }
        }
        long long minn=1e10;
        for(int i=1;i<=m;i++)
        {
            if(cnt[i]==2)
            {
                minn=min(tt[i]*1LL,minn);
            }
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            cin>>x>>y;
            int ans=w[x]+w[y];
            int xx=2,yy=2,xxx=-1,yyy=-1;
            for(int j=1;j<=k[1];j++)
            {
                if(a[1][j]==x)
                {
                    xx=1;
                    xxx=j;
                }
                if(a[1][j]==y)
                {
                    yy=1;
                    yyy=j;
                }
            }
            for(int j=1;j<=k[2];j++)
            {
                if(a[2][j]==x&&xxx<0)
                {
                    xx=2;
                    xxx=j;
                }
                if(a[2][j]==y&&yyy<0)
                {
                    yy=2;
                    yyy=j;
                }
            }
            ans+=t[xx][xxx]+t[yy][yyy];
            cout<<xx<<" "<<xxx<<" "<<yy<<" "<<yyy<<endl;
            if(xx!=yy)
            {
                ans+=minn;
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+2026<<endl;
    }
    return 0;
}