#include<bits/stdc++.h>
using namespace std;
long long n,m,r=0,l=pow(10,12),mid;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i <= n;i++)
    {
        cin>>a[i];
        if(a[i] > r)
        {
            r=a[i];
        }
        if(a[i] < l)
        {
            l=a[i];
        }
    }
    sort(a+1,a+1+n);
    while(l <= r)
    {
        mid=(l+r)/2;
        long long cz=0,ii=0;
        for(int i=1;i <= n;i++)
        {
            if(a[i] > mid)
            {
                break;
            }
            cz+=abs(mid-a[i]);
            ii=i;
        }
        if(cz > m)
        {
            r=mid;
        }
        else if(cz < m)
        {
            l=mid;
        }
        else if(cz == m)
        {
            cout<<ii;
            return 0;
        }
    }
    return 0;
}
