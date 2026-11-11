#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        int a[200005],road[200005]={0,1};
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=d;j++)
            {
                int x=1;
                while(a[i]+j>=a[i+x])
                {
                    if(a[i]+j==a[i+x])
                    {
                        road[i+1]++;
                        break;
                    }
                    x++;
                }
            }
        }
        cout<<road[n];
    }
    return 0;
}
