#include <bits/stdc++.h>
using namespace std;
int a[200005];
int f(int n)
{
    int cnt=0;
    while(n)
    {
        if(n%2==1)
        {
            cnt++;
        }
        n/=2;
    }
    return cnt;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int imax=0;
    if(n<=20)
    {
        for(int o=1;o<=(1<<n);o++)
        {
            int t=o;
            if(f(t)!=m)
            {
                continue;
            }
            int cur=INT_MAX;
            int pos=0;
            while(t)
            {
                pos++;
                if(t%2==1)
                {
                    cur&=a[pos];
                }
                t/=2;
            }
            imax=max(imax,cur);
        }
        cout<<imax;
    }
    else if(m<=2000)
    {
        if(m==1)
        {
            sort(a+1,a+n+1);
            cout<<a[1];
        }
        if(m==n)
        {
            int ans=INT_MAX;
            for(int i=1;i<=n;i++)
            {
                ans&=a[i];
            }
            cout<<ans;
        }
        if(m==2)
        {
            int imax=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    imax=max(imax,a[i]&a[j]);
                }
            }
            cout<<imax;
        }
    }
    else
    {
        sort(a+1,a+n+1,greater<int>());
        cout<<(a[2001]^a[(n-2026+n)%n]);
    }
    return 0;
}
