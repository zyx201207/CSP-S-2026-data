#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[500005];
long long s[500005];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <=n;i++)
    {
        s[i] = s[i-1] + a[i];
    }
    int q = 0;
    for(int i = 2;i <= n;i++)
    {
        q = s[i-1] - s[i-1-(ans+1)];
        while(i > ans+1 && (ans+1)*a[i] - q <= m)
        {
            ans++;
            q = s[i-1] - s[i-1-(ans+1)];
        }
    }
    cout << ans+1;
    return 0;
}

