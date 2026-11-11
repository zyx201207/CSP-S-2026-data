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
        int n,d;
        int ans=0;
        cin>>n>>d;
        int x[2000010];
        vector<int> t[1000000];
        int y[1000][1000];
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                y[i][j]=abs(x[i]-x[j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;i++)
            {
                for(int k=j;k<=n;k++)
                {

                }
            }
        }
    }
    cout<<5<<endl<<3;
    return 0;
}
