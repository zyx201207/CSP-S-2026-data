#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long n, m;
long long a[maxn];
long long cnt;
bool ispingfang(long long x)
{
    long long t=x+1;
    for(int i=1;i*i<=t;i++)
    {
        if(i*i==t)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(m==1)
    {
        long long max1=-1;
        for(int i=1;i<=n;i++)
        {
            max1=max(max1,a[i]);
            cout << max1;
            return 0;
        }
    }
    if(m==n)
    {
        long long sum=a[1];
        for(int i=2;i<=n;i++)
        {
            sum&=a[i];
            cout << sum;
            return 0;
        }
    }
    if(m==2)
    {
        long long maxx=0;
        for(int i=1;i<=n-1;i++)
        {
            long long sum=a[i];
            long long maxsum=0;
            for(int j=i+1;j<=n;j++)
            {
                sum&=a[j];
                maxsum=max(maxsum,sum);
                sum=a[i];
            }
            maxx=max(maxx,maxsum);
        }
        cout << maxx;
        return 0;
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(ispingfang(a[i]==false))
        {
            flag=false;
        }
    }
    if(flag==true)
    {
        sort(a+1,a+n+1);
        int q=a[n];
        for(int i=1;i<=m;i++)
        {
            q/=2;
        }
        cout << q;
        return 0;
    }
    return 0;
}
