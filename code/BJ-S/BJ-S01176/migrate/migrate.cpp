#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,xx[2000005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>xx[i];
        }
        long long minn=n+10,ans=0,s=xx[2]-xx[1];
        for(int x=1;x<=n;x++)
        {
            for(int y=x+1;y<=n;y++)
            {
                if(xx[j]-xx[x]>d && xx[j]-xx[x]<2*d)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
