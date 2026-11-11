#include <bits/stdc++.h>
using namespace std;

long long n,a[200001];
char c[200001];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    long long ans=0,f=1,l=n;
    for(;f<=l;)
    {
        if(c[l]==c[f])
        {
            if(a[f]>a[l])
            {
                a[f]=a[f]-a[l];
                l--;
            }
            else if(a[f]==a[l])
            {
                f++;
                l--;
            }
            else
            {
                a[l]=a[l]-a[f];
                f++;
            }
        }
        else
        {
            if(a[f]>a[l])
            {
                ans+=a[l];
                a[f]=a[f]-a[l];
                l--;
            }
            else if(a[l]==a[f])
            {
                ans+=a[l];
                l--;
                f++;
            }
            else
            {
                ans+=a[f];
                a[l]=a[l]-a[f];
                f++;
            }
        }
    }
    cout<<ans;
    return 0;
}
