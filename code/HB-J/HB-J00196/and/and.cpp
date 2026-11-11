#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,sum=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            sum=a[i];
            for(int j=1;j<=n;j++)
            {
                if(i=j)
                {
                    continue;
                }
                sum=sum&a[j];
                if(sum>cnt)
                {
                    cnt=sum;
                }
            }
        }
        cout<<cnt;
    }
    else if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            sum=a[i];
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                sum=sum&a[j];
            }
            if(sum>cnt)
            {
                cnt=sum;
            }
        }
        cout<<cnt;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            sum=a[i];
            for(int j=1;j<=m;j++)
            {
                if(i==j)
                {
                    j--;
                    continue;
                }
                sum=a[i]&sum;
            }
            if(sum>cnt)
            {
                cnt=sum;
            }
        }
        cout<<cnt;
    }
    return 0;
}
