#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int D;
int k;
int sum;
int ans=1;
int a[500010];
bool A=1;
bool B=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]!=i)
        {
            A=0;
        }
    }
    sort(a+1,a+n+1);
    if (A)
    {
        while (1)
        {
            k++;
            sum+=k;
            if (sum>m)
            {
                break;
            }
            ans++;
        }
        cout<<ans;
        return 0;
    }
    D=a[2]-a[1];
    for (int i=1;i<=n-1;i++)
    {
        if (D!=a[i+1]-a[i])
        {
            B=0;
        }
    }
    if (B)
    {
        while (1)
        {
            k+=D;
            sum+=k;
            if (sum>m)
            {
                break;
            }
            ans++;
        }
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
