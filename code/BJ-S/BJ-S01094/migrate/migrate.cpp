#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],minn=1e9,ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(abs(x[i]-x[j])<=d)
                {
                    if(abs(x[i]-x[j])==minn)ans++;
                    minn=min(abs(x[i]-x[j]),minn);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
