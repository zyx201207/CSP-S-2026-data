#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
long long num;
int maxn;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    maxn=1;
    int j;
    for(int i=1;i<=n;i++)
    {
        j=i+maxn;
        while(j<=n)
        {
            num=(j-i)*a[j]-(sum[j-1]-sum[i-1]);
            if(num<=m)
            {
                maxn++;
            }
            else
            {
                break;
            }
            j=i+maxn;
        }
    }
    cout<<maxn;
    return 0;
}
