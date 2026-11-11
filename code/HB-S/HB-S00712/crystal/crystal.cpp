#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
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
    for(int i=2;i<=n;i++)
    {
        long long sum=0,minn=0x3f3f3f3f3f;
        for(int j=1;j<=n-i+1;j++)
        {
            for(int f=j;f<=j+i-1;f++)
            {
                sum+=a[f]-a[j];
            }
            minn=min(minn,sum);
        }
        if(m<minn)
        {
            cout<<i-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
