#include<bits/extc++.h>
using namespace std;
long long n,m,ans=0,sum=0,l=0;
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),cmp);
    long long k=a[0];
    for(int i=0;i<n;i++)
    {
        a[i]=k-a[i];
    }
    k=0;
    for(int r=0;r<n;r++)
    {
        sum+=a[r]-a[l];
        if(sum>m)
        {
            while(sum>m)
            {
                l++;
                sum-=(a[l]-a[l-1])*(r-l+1);
            }
        }
        ans=max(r-l+1,ans);
    }
    cout<<ans;
    return 0;
}
