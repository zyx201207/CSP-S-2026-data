#include<bits/stdc++.h>
using namespace std;

long long n,m,ans,a[50005],sum[500005];
bool cmp(long long a,long long b)
{

    return a>b;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++)
    {
        long long t=m;
        for(int j=i+1;j<=n;j++)
        {
            t=t-abs(a[i]-a[j]);
            if(t==0)
            {
                sum[i]=j-i+1;
                break;
            }
            if(t<0)
            {
                sum[i]=j-i;
                break;
            }

        }

    }
    sort(sum+1,sum+n+1,cmp);
    cout<<sum[1];
    return 0;
}
