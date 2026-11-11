#include<bits/stdc++.h>
using namespace std;

long long n,m,a[2000005],ans,sum[20000005],cnt[20000005];

bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n>2000)
    {

            ans=a[1];
            for(int i=1;i<=m;i++)
            {
                ans&=a[i];
            }
            cout<<ans;
            return 0;

    }
    else if(n==2000)
    {
        if(m==1)
        {
            cout<<a[1];
            return 0;
        }
        else if(m==n)
        {
            for(int i=2;i<=n;i++)
            {
                ans+=(a[i]&a[i-1]);
            }
            cout<<ans;
            return 0;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    cnt[j]=(a[j]&a[i]);
                    sort(cnt+i+1,cnt+n+1,cmp);
                    sum[i]=cnt[i+1];
                }

            }
            cout<<sum[1];
            return 0;
        }
    }
    else
    {

        ans=a[1];
        for(int i=1;i<=m;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;

    }


    return 0;
}
