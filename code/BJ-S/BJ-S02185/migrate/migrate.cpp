#include<bits/stdc++.h>
using namespace std;
int c,t,now;
long long n,d,x[2000005],ans;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        now=n;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            if(x[i]-x[i-1]>d)
            {
                now=i-1;
                break;
            }
        }
        ans=0;
        for(int i=1;i<=now-3;i++)
        {
            if(x[i+3]-x[i]<=d) continue;
            else ans++;
        }
        cout<<ans<<"\n";

    }
    return 0;
}
