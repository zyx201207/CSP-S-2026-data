#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001];
bool p(long long c,long long d)
{
    return c>=d;
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
    sort(a+1,a+n+1,p);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    else if(m==2)
    {
        long long a2=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                a2=max(a2,a[i]&a[j]);
            }
        }
        cout<<a2;
        return 0;
    }
    else if(m==n-1)
    {
        long long ta=0;
        for(int i=1;i<=n;i++)
        {
            long long la=0,dddd=1;
            for(int j=1;j<=n;j++)
            {
                if(i!=j)
                {
                    if(la==0&&dddd==1)
                    {
                        la+=a[j];
                        dddd=0;
                    }
                    else
                    {
                        dddd=0;
                        la=la&a[j];
                    }
                }

            }
            ta=max(ta,la);
        }
        cout<<ta;
        return 0;
    }
    long long ans=a[1];
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[i];
    }
    cout<<ans;
    return 0;
}
