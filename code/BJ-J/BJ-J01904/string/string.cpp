#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],vis,cnt,L;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    ll l=1,r=n;
    while(l<r)
    {
        if(c[l]==c[r])
        {
            if(a[l]==a[r])
            {
                a[l]=a[r]=0;
                l++;r--;
                continue;
            }
            else if(a[l]>a[r])
            {
                a[l]-=a[r];
                a[r]=0;
                r--;
                continue;
            }
            else
            {
                a[r]-=a[l];
                a[l]=0;
                l++;
                continue;
            }
        }
        else
        {
            if(a[l]==a[r])
            {
                cnt+=a[l];
                a[l]=a[r]=0;
                l++;r--;
                continue;
            }
            else if(a[l]>a[r])
            {
                cnt+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
                continue;
            }
            else
            {
                cnt+=a[l];
                a[r]-=a[l];
                a[l]=0;
                l++;
                continue;
            }
        }
    }
    cout<<cnt;
    return 0;
}
