#include<bits/stdc++.h>
using namespace std;
const int mx=5000+50;
long long a[mx],f[mx][mx],v[mx][mx];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--)
    {
        int n;
        long long d;
        long long ans=0;
        cin>>n>>d;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for (int i=1;i<=n;i++)
        {
            f[i][i]=1;
            for (int j=i+1;j<=n;j++)
                f[i][j]=v[i][j]=0;
        }
        for (int i=1;i<n-1;i++)
        {
            int r=2,l=1;
            while (r<=n)
            {
                for (int j=i;j<=l;j++)
                {
                    for (int k=l+1;k<=n && a[k]<=a[j]+d;k++)
                    {
                        f[i][k]+=f[i][j];
                        r=max(r,k);
                    }
                }
                l=r;
                r++;
            }
        }
        //for (int i=1;i<=n;i++)
        //{
        //    for (int j=1;j<=n;j++)
        //    {
        //        cout<<f[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j<=n;j++)
            {
                if (f[i][j]==2)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
