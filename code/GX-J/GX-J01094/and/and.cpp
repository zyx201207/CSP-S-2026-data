#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum = -1;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        int a[100005] += x;
    }
    for (int i = 0;i < 100005;i++)
    {
        for (int j = 1;j <= 100005;j++)
        {
            sum = max(a[i] & a[j],sum);
        }
    }
    cout << sum;
    return 0;
}
