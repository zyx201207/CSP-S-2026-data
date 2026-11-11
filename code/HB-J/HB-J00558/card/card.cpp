#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[1000010],sum;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 1;i <= n;i ++)
        sum = max(a[i],a[i+1]);
    cout << n << " " << m << " " << sum + 2;
    return 0;
}
