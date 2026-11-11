#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000005], ans;
bool cmp(long long a, long long b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1, a+n+1, cmp);
    int j=1, sum=0;
    for(long long i=2;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(i-j);
        if(sum<=m) ans=max(ans, i-j+1);
        else
        {
            while(sum>m)
            {
                sum=sum-(a[i]-a[j]);
                j++;

            }
            if((a[i]-a[i-1])*(i-j)<=m)ans=max(ans, i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
