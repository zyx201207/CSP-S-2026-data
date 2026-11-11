#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500001],ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>=2000)
    {
        int y=n/5;
        for(long long i=1;i<=y;i++)
    {

        for(long long j=i;j<=y;j++)
        {
            long long z=m,ss=0;
            for(int x=i;x<=y;x++)
            {

                if(a[j]>=a[x]&&z>0)
                {
                    z=z-(a[j]-a[x]);
                    ss++;
                }
                else
                {
                    if(a[j]-a[x]==0&&a[j]>=a[x])
                    {
                        ss++;
                        continue;
                    }
                    else
                    {
                    break;
                    }
                }

                //cout<<i<<endl<<a[j]<<endl<<a[x]<<endl<<z<<endl<<ss<<endl<<"*";
            }
            ans=max(ss,ans);
        }

    }
    }
    else
    {
    for(long long i=1;i<=n;i++)
    {

        for(long long j=i;j<=n;j++)
        {
            long long z=m,ss=0;
            for(int x=i;x<=n;x++)
            {

                if(a[j]>=a[x]&&z>0)
                {
                    z=z-(a[j]-a[x]);
                    ss++;
                }
                else
                {
                    if(a[j]-a[x]==0&&a[j]>=a[x])
                    {
                        ss++;
                        continue;
                    }
                    else
                    {
                    break;
                    }
                }

                //cout<<i<<endl<<a[j]<<endl<<a[x]<<endl<<z<<endl<<ss<<endl<<"*";
            }
            ans=max(ss,ans);
        }

    }
    }
    cout<<ans;
    return 0;
}

