#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
bool check(int mid)
{
    int cnt=0;
    for(int i=1;i<=mid;i++)
    {
        cnt+=a[mid]-a[i];
    }
    return cnt<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    int ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
