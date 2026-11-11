#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll m,a[500005];
int n;
bool check(int num)
{
    unsigned long long dist=0;
    for(int i=n-num+1;i<n;i++)
    {
        dist+=a[n]-a[i];
    }
    if(dist<=m) return true;
    for(int i=n-1;i>=num-1;i--)
    {
        dist+=(a[i]-a[i-num+1]);
        dist-=(num-1)*(a[i+1]-a[i]);
        if(dist<=m) return true;

    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=n,mid=(l+r)/2,ans;
    while(l<=r)
    {
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
        mid=(l+r)/2;
    }
    cout<<mid;
}
/*
5 8
-3 -1 2 2 7
*/
