#include <bits/stdc++.h>
using namespace std;
long long n,d;
long long c,t;
long long a[2000005],ans;
int o()
{
    memset(a,0,sizeof(a));
    n=0,d=0,ans=0;
    cin>>n>>d;

    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long i=1,j=2;
    while (1)
    {
        if (j<=n && a[j]-a[i]>d && j-i==3 && a[j]-a[i]<2*d)
        {
            ans++;
            i+=1;
        }
        else if (j==n && (a[j]-a[i]<=d || j-i<=4))
        {
            break;
        }
        else
        {
            j+=1;
        }
    }
    cout<<ans<<endl;
    return 0;

}




int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for (long long i=1;i<=t;i++)
    {
        o();
    }




    fclose(stdin);
    fclose(stdout);
    return 0;
}
