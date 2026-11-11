#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int b[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

        }
        for(int i=1;i<=n-3;i++)
        {
            bool f=0;
            if(a[i+3]-a[i]>d)
            {
                for(int j=i;j<i+3;j++)
                {
                    if(a[j+1]-a[j]>d)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==1)  continue;
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
