#include <bits/stdc++.h>
using namespace std;
const long long N=2000005;
long long a[N];
long long cnt1,cnt2;
long long n,d;
void dfs(long long u,long long en,long long len)
{
    //cout<<u<<" "<<len<<endl;
    if(u==en && len==cnt1)
    {
        cnt2++;
        return ;
    }
    for(long long i=u+1;i<=en;i++)
    {
        if(a[i]-a[u]<=d)
        {
            dfs(i,en,len+1);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long ans=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                bool flag=0;
                for(long long k=i;k<j;k++)
                {
                    if(a[k+1]-a[k]>d)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    break;
                }
                long long last=i;
                cnt1=1;
                for(long long k=i+1;k<=j;k++)
                {
                    if(a[k]-a[last]>d)
                    {
                        cnt1++;
                        last=k-1;
                    }
                }
                cnt2=0;
                //cout<<i<<" "<<j<<":"<<endl;
                dfs(i,j,0);
                //cout<<cnt2<<endl;
                if(cnt2==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
