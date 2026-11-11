#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[100100];
long long ans = 0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    int z = n / 2;
    if(n % 2 != 0)
    {
        z++;
    }
    for(int i = n; i >= z; i--)
    {
        if(a[i] == a[z])
        {
            z = i;
            break;
        }
    }
    for(int i = z; i >= 1; i--)
    {
        if(a[i] == a[z])
        {
            ans++;
            continue;
        }
        if(m >= a[z] - a[i])
        {
            int x = a[z] - a[i];
            m -= x;
            ans++;
            a[i] = a[z];
        }
    }
    cout << ans;
    return 0;
}
