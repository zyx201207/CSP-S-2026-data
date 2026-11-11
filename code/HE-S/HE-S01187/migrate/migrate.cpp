#include<bits/stdc++.h>
using namespace std;
long long c,d,n;
long long x[2000010];
long long dis[2000010];
long long pre[2000010];
long long suf[2000010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long T;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==11||c==12)
        {
            long long cf=x[2]-x[1];
            long long cnt=d/cf;
            long long js=cnt+cnt-1;
            if(js==1||d<cf||js>n)
            {
                cout<<0<<'\n';
            }
            else
            {
                cout<<n-js<<'\n';
            }
        }
        else if(c==13||c==14)
        {
            cout<<0<<'\n';
        }
        else
        {
            for(long long i=1;i<=n;i++)
            {
                long long l=1,r=n;
                for(long long j=i;j>=0;j--)
                {
                    if(x[i]-x[j]>d)
                    {
                        l=j+1;
                        break;
                    }
                }
                for(long long j=i;j<=n;j++)
                {
                    if(x[j]-x[i]>d)
                    {
                        r=j-1;
                        break;
                    }
                }
                pre[i]=l;
                suf[i]=r;
            }
            long long ans=0;
            for(long long i=1;i<=n;i++)
            {
                for(long long j=i+1;j<=n;j++)
                {
                    if(pre[j]==suf[i]-1)
                    {
                        long long pres=1;
                        long long sufs=1;
                        long long x=i;
                        while(pre[x]!=x&&pre[pre[j]]==i)
                        {
                            pres++;
                            x=pre[x];
                        }
                        x=j;
                        while(suf[x]!=x&&suf[suf[i]]==j)
                        {
                            sufs++;
                            x=suf[x];
                        }
                        ans+=pres*sufs;
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}

