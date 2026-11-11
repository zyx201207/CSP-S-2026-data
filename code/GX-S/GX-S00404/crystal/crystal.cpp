#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],ans=1,sum=0,b=1;
long long n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n-1;i++)
    {
        c[i]=a[i+1]-a[i];
    }

    for(int i=1;i<=n-1;i++)
    {
        if(sum+c[i]*b<=m)
        {
            sum+=c[i]*b;
            b++;

        }
        else
        {
            if(b>ans)
            {
                ans=b;
            }
            b=1;
            if(c[i]<=m)
            {
                sum=c[i];
            }
            else
            {
                sum=0;
            }
        }
    }
    if(b>ans)
            {
                ans=b;
            }
    cout<<ans;
    return 0;
}
