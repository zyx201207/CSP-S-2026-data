#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[50000005];
long long b[50000005];
long long c[50000005];
long long x[500005];
long long y[500005];
int main ()
{
    freopen("subway.in","w",stdin);
    freopen("subway.out","r",stdout);
    cin >>c>>n>>m>>d>>q;
    long long ans=a[1];
    for (int i=1;i<=m;i++)
    {
        cin >>a[i];
    }
    for (int i=1;i<=q;i++)
    {
        cin >>x[i]>>y[i];
    }
    int an=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=m*2;j++
        {

            cin >>b[j];
            if (b[j]!=y[i]&&j%2==0&&j>=2)
                {
                    ans+=b[j+1];
                }
                else if (b[j]==y[i]&&j%2==0&&j>=2)
                {
                    ans+=b[j+1]+a[b[j];
                    an++;
                }

        }
        if (an>0)
        {
            cout <<ans<<endl;
            an=0;
            ans=0;
            break;
        }
        ans=0;
        an=0;
        long long v=0;
        if (i!=1)
        {
            for (int j=1;j<=m*2&&j%2==0&&j>=2;j++)
            {
                for (int g=1;g<=m*2&&g%2==0&&g>=2;g++)
                {
                v++;
                    if (b[g]==c[j])
                    {
                        ans+=c[j+1]+b[g+1];
                        break;
                    }
                    else if (c[j]!=y[g]&&j%2==0&&j>=2&&v=m)
                    {
                        ans+=c[g+1];
                        v=0;
                    }
                }
                if (b[j]==y[i])
                {
                    ans+=b[i+1]+a[b[i]];
                    cout <<ans<<endl;
                    ans=0;
                    break;
                }
            }
        }
        for (int j=0;j<=m*2;j++)
        {
            c[i]=b[i];
        }
    }
    return 0;
}
