#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],arr[500005];
bool check(int num)
{
    bool ret=0;
    for(int i=1;i+num-1<=n;i++)
    {
        long long tmp=arr[i+num-1]-arr[i-1]+m;
        if(tmp>=num*1ll*a[i+num-1]) ret=1;
    }
    return ret;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        arr[i]=arr[i-1]+a[i];
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}