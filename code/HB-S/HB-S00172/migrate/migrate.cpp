#include <bits/stdc++.h>
using namespace std;
long long a[2000010],q[2][1000000];

int main()
{

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    for(int t2=1;t2<=t;t2++)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int e=1;e<=n;e++)
        {
            for(int r=e+2;r<=n;r++)
            {
                memset(q,0,sizeof(q));
                long long head=0,tail=0,way=0,mn=2.1e9;
                tail++;
                q[1][tail]=e;
                q[0][tail]=0;
                while(head<tail)
                {
                    head++;
                    long long now=q[1][head],cos=q[0][head],n2=now+1;
                    if(now==r)
                    {
                        if(cos<mn)
                        {
                            way=1;
                            mn=cos;
                            continue;
                        }
                        if(cos==mn)
                        {
                            way++;
                        }
                    }
                    if(cos>=mn)
                    {
                        continue;
                    }
                    if(way>2)
                    {
                        break;
                    }
                    while(a[n2]-a[now]<=d&&n2<=r)
                    {
                        tail++;
                        q[1][tail]=n2;
                        q[0][tail]=cos+1;
                        n2++;
                    }
                }
                if(way==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;

}
