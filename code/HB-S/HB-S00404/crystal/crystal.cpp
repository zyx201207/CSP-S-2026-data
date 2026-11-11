#include<bits/stdc++.h>
using namespace std;
long long a[500010],ans=1,sum,maxx=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long x,y;
    cin>>x>>y;
    for(long long i=0;i<x;i++)
    {
        cin>>a[i];
    }
    sort(a,a+x);
    long long l=0,r=0;
    while(r<x-1)
    {
        sum+=a[r];
        if(a[r+1]*(r-l+1)-sum<=y)
        {
            maxx++;
            r++;
            ans=max(maxx,ans);
        }
        else
        {
            if(a[r+1]-a[r]>y)
            {
                maxx=1;
                sum=a[r+1];
                l=r+1;
                r+=2;
            }
            else
            {
                while(l<r&&a[r+1]*(r-l+1)-sum>y)
                {
                    sum-=a[l];
                    l++;
                    maxx--;
                }
                maxx++;
                r++;
                ans=max(maxx,ans);
            }
        }
    }
    cout<<ans;
    return 0;
}
