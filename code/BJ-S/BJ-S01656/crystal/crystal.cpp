#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long check(int mid)
{
    long long ans=0;
    for(int i=1;i<=mid-1;i++)
    {
        ans=ans+(a[mid]-a[i]);
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
  //  cout<<n<<" "<<m<<" ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,ans;
    while(l<=r)
    {
        int mid=(l+r)>>1;
       // cout<<mid<<"\n";
       // cout<<check(mid)<<"\n";
        if(check(mid)<=m)
        {
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
