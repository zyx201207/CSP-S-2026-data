#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
#define int long long
long long a[N];
int n,m;
//5 5 1 2 4 8 9
long long o1,o2;
long long check(int x)
{
    long long sum = 0;
    if(x == o1)
        return o2;
    else if(x < o1)
    {
        for(int i = o1;i >= x;i--)
            sum += a[i]-a[o1];
        o2 = sum+o2+(a[x]-a[o1])*(x-1);
        o1 = x;
        return o2;
    }
    else
    {
        for(int i = o1;i <= x-1;i++)
            sum += a[o1]-a[i];
        o2 = sum+o2+(a[x]-a[o1])*(x-1);
        o1 = x;
        return o2;
    }
}
void solve()
{
    int ans = 1;
    int l = 1,r = n;
    int mid = n+1>>1;
    o1 = mid;
    for(int i = 1;i < o1;i++)
        o2 += a[o1]-a[i];
    //cout << mid << endl;
    while(l < r)
    {
        mid = l+r>>1;
        //cout << l << ' ' << r << ' ' << mid << endl;
        if(check(mid) > m)
            r = mid;
        else
        {
            l = mid+1;
            ans = mid;
        }
    }
    cout << ans;
    return;
}
void solve1(long long k)
{
    long long ans = 1;
    long long i;
    for(i = 2;i <= n && ((k*i*(i-1)/2 <= m && k*i*(i-1)%2 == 0) || k*i*(i-1)/2 < m);i++)
    {
        //cout << k*i*(i-1)/2 << endl;
        continue;
    }
    cout << i-1;
    return;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    bool f = 1;
    long long k = a[2]-a[1];
    //for(int i = 1;i <= n;i++)
    //    cout << a[i] << endl;
    for(int i = 2;i < n;i++)
    {
        if(a[i+1]-a[i] != k)
        {
            f = 0;
            break;
        }
    }
    if(f)
        solve1(k);
    else
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
