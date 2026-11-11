#include<bits/stdc++.h>
using namespace std;
long long m1[500005];
long long a[5005][5005];
long long t[5005][5005];
long long k[500005];
bool l[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long n,c,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>m1[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        int x,y,z,o;
        cin>>x>>y;
        ans+=m1[x];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==x)
                {
                    z=i;
                    ans+=t[i][j];
                }

                if(a[i][j]==y)
                {
                    o=i;
                    ans+=t[i][j];
                }
            }
        }
        for(int j=1;j<=k[z];j++)l[a[z][j]]=1;
        for(int i=1;i<=k[o];i++)
        {
            if(l[a[o][i]]==1)
            {
                for(int j=1;j<=k[z];j++)
                {
                    if(a[z][j]==a[o][i])
                    {
                        ans+=t[z][j];
                        ans+=t[o][i];
                        break;
                    }
                }
            }
        }
        ans+=m1[y];
        cout<<ans<<endl;
    }
return 0;
}
