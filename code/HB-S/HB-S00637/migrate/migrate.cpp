#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(j==i+2&&a[j]-a[i]<=d)
                {
                    ans++;
                }else if(j==i+3&&a[j]-a[i]>d&&a[j-1]-a[i]<=d&&a[j]-a[i+1]<=d)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
