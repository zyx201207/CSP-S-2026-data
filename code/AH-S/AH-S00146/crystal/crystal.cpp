#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,a[500005];
void try45()
{
    ll ans=1;
    for(int i = 1;i <= n;i++)
    {
        ll k = 0;//已经花费
        ll sum = 0;//让多少个点变
        for(int j = i-1;j >= 1;j--)
        {
            k+=a[i]-a[j];
            if(k>m)
            {
                break;
            }
            sum++;
        }
        ans = max(ans,sum+1);
    }
    cout << ans;
    return;
}
void tryjia15()
{
    ll ans=1;
    for(int i = -200;i <=200;i++)
    {
        int x=1;
        ll k = 0;//已经花费
        ll sum = 0;//让多少个点变
        for(;x <= n;x++)
        {
            if(a[x]>i)
            {
                break;
            }
        }
        x--;
        for(int y = x-1;y >= 1;y--)
        {
            k+=a[x]-a[y];
            if(k>m)
            {
                break;
            }
            sum++;
        }
        ans = max(ans,sum+1);
    }
    cout << ans;
    return;
}
void trydengcha()
{
    int d = a[2]-a[1];
    if(d==0)
    {
        cout << n;
        return;
    }
    ll k=0;
    while(1ll*d*k*(k+1)/2<m)
    {
        k++;
    }
    cout << k;
    return ;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(n<=5001)
    {
        try45();
    }
    else if(a[1]>=-200&&a[n]<=200)
    {
        tryjia15();
    }
    else
    {
        trydengcha();
    }
    return 0;
}
