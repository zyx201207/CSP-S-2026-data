#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m,cnt=0,sum=0;
    cin >> n >> m;
    int a[n+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum+=a[i];
    sum/=n;
    int jl;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<sum && a[i+1]>=sum)
        {
            sum=a[i+1];
            jl=i+1;
            break;
        }
    }
    for(int i=jl;i>=1;i++)
    {
        if(m>=sum-a[i])
        {
            m-=sum-a[i];
            cnt++;
        }
        else break;
    }
    int cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(sum==a[i]) cnt2++;
    }
    cout << cnt+cnt2-1;
    return 0;
}
