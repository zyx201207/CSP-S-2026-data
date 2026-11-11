#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==2)
    {
        int sum=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                sum=max(sum,(a[i]&a[j]));
            }
        }
        cout<<sum;
        return 0;
    }
    if(m==n)
    {
        int sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum=(sum&a[i]);
        }
        cout<<sum;
        return 0;
    }
    if(m==n-1)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            int s;
            if(i==1)
            {
                s=a[2];
                for(int j=3;j<=n;j++)
                {
                    s=(s&a[j]);
                }
            }
            else
            {

                s=a[1];
                for(int j=2;j<=n;j++)
                {
                    if(j!=i)
                    {
                        s=(s&a[j]);
                    }
                }
            }
            sum=max(sum,s);
        }
        cout<<sum;
        return 0;
    }
    return 0;
}
