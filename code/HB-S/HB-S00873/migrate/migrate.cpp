#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d,gs=0;
        cin>>n>>d;
        int a[2000005];
        bool b[2000005];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                for(int k=1;k<=b;k++)
                {
                    if(a[i]+k==a[j])
                    {
                        gs++;
                    }
                }
            }
        }
        cout<<gs<<endl;
    }
    return 0;
}
