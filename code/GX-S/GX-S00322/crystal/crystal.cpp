#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[500005],s=INT_MIN;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long m1=m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
    {
        long long t=0,l=0;
        while(m1>0&&j<=n&&i-t>0)
        {
            if (a[j]==a[i])
            {
                j++;
                continue;
            }
            if(a[j]-a[i]<a[i]-a[i-t])
            {
                m1-=a[j]-a[i];
                j++;
            }
            else
            {
                m1-=a[i]-a[i-t];
                t++;
            }
            l++;
        }
        s=max(s,l);
    }
    cout<<s;
    return 0;
}
