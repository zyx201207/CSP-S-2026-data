#include<bits/stdc++.h>
using namespace std;
int dfs(int d,int a[10000001],int u,int v);
{
    int sum=0;

    for(int i=u;i<=v;i++)
    {
        int q;
        for(int j=i;j<=v;j++)
        {
            int q;
            q=j-1;
            if(a[j]-a[i]>d)
            {

                sum++;
                break;
            }
        }
        i=q;
    }
    return sum;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","r",stdout);
    long long c,t;
    cin >> c >>t;
    for(int i=1;i<=t;i++)
    {
        long long n;
        long long d;
        long long a[n+1];
        cin >> n >> d;
        for(int j=1;j<=n;j++)
        {

            cin >> a[j];
        }
        for(int u=1;u<=n;u++)
        {

            for(int v=u;v<=n;v++)
            {

                dfs(d,a[n+1],u,v);
            }
        }


    }
    cout << sum;
    return 0;
}
