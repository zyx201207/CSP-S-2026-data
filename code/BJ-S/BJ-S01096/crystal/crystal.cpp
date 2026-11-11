#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m;
int ans=1;
int b[500005];
int f[500005];
long long sum=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i-1]=a[i]-a[i-1];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i];
        sum+=b[i]*i;
    }
    if(sum<=m)
    {
        ans=n;
    }
    else if(n<=50000)
    {
        for(int i=1;i<n;i++)
        {
            long long t=m;
            for(int j=i+1;j<=n;j++)
            {
                //cout<<i<<"  "<<j<<" "<<t<<"\n";
                if(t-b[j-1]*(j-i)<0)
                {
                    f[i]=j-i;
                    break;
                }
                else if(j==n)
                {
                    f[i]=j-i+1;
                }
                t-=b[j-1]*(j-i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            //cout<<f[i]<<"\n";
            ans=max(ans,f[i]);
        }
    }
    else if(b[1]==b[2])
    {
        int x=b[1];
        for(int i=1;i<=n;i++)
        {
            if(m-x*i>0)
            {
                m-=x*i;
                ans++;
            }
            else if(m-x*i==0)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}

