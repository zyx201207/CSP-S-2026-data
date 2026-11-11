#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], t[500005], n, m;
bool check(int num)
{
    if (num==1)
        return 1;
    for (int i=1;i+num-1<=n;i++)
    {
        int sum=0;
        for (int j=i+1;j<=i+num-1;j++)
        {
            int o=j-i;
            sum+=t[j]*o;
        }
        if(sum<=m)
            return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool oka=1, okb=1;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]!=i)
            oka=0;
    }
    sort(a+1, a+n+1);
    for (int i=2;i<=n;i++)
        t[i]=a[i]-a[i-1];
    for (int i=3;i<=n;i++)
    {
        if (t[i]!=t[i-1])
        {
            okb=0;
            break;
        }
    }
    if (oka)
    {
        //cout << 0;
        if (m==0)
        {
            cout << 0;
            return 0;
        }
        int sum=1;
        int i=2;
        for (;i<=n;i++)
        {
            if (sum+i<=m)
                sum+=i;
            else
                break;
        }
        cout << i;
        return 0;
    }
    if (okb)
    {
        if (m==0)
        {
            cout << 0;
            return 0;
        }
        int i=2, kl=t[2];
        //cout << 1;
        int sum=kl;
        for (;i<=n;i++)
        {
            if (sum+i*kl<=m)
                sum+=i*kl;
            else
                break;
        }
        cout << i;
        return 0;
    }
    int l=1, r=n, ans=1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            ans=max(mid, ans);
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout << ans;
    return 0;
}
