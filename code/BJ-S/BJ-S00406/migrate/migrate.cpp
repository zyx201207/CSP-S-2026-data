#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        long long a[n+1];
        for(int j=1;j<=n;j++)cin>>a[j];
        long long ans=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]+d+1==a[j+3])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
