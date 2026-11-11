#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> b[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=b[n]-b[i];
        a[i]+=a[i-1];
        //cout << a[i] << ' ';
    }
    //cout << '\n';
    for(long long i=1;i<=n;i++)
    {
        long long l=1,r=i;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(a[i-1]-a[mid-1]-(b[n]-b[i])*(i-mid)<=m)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout << ans;
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
