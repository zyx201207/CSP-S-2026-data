#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n+5],b[n+2][n+2],d[n+2][n+2];
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    if(m==0)
    {
        int s;
        for(int i=1;i<=n;i++)
        {
            int k=1;
            for(int j=1;j<=n;j++){
                if(a[i]==a[j]&&i!=j)
                {
                    k++;
                }
            }
            s=max(s,k);
        }
        cout<<s;

    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=a[i]-a[j];
                if(b[i][j]<0)
                {
                    b[i][j]*=-1;
                }
            }

        }
        for(int i=1;i<=n;i++)
        {
            int c[n+5];
            for(int j=1;j<=n;j++)
            {

                c[j]=b[i][j];


            }
            sort(c+1,c+n+1);
            long long sun=0;
            for(int j=1;j<=n;j++)
            {
                sun+=c[j];
                d[i][j]=sun;
                if(d[i][j]<0)
                {
                    d[i][j]*=-1;

                }
            }
        }
        int e[n+5];
        for(int i=1;i<=n;i++)
        {
            int maxi=0;
            for(int j=1;j<=n;j++)
            {
                if(d[i][j]<=m)
                {
                    maxi++;
                }
            }
            e[i]=maxi;
        }
        sort(e+1,e+n+1);
        cout<<e[n];
    }

    return 0;
}
