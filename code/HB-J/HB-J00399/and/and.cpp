#include <bits/stdc++.h>
using namespace std;

int n,m,a[200005],maxn,ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    if(m == 1)
    {
        cout << maxn;
    }
    else if(m == n)
    {
        ans = a[1];
        for(int i = 2;i <= n;i++)
            ans = ans&a[i];
        cout << ans;
    }
    else
    {
        sort(a+1,a+n+1);
        ans = maxn;
        for(int i = n-1;i >= n-m+1;i--)
            ans = ans&a[i];
        cout << ans;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
