#include <bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout)
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    cout << m << " " << n-m << " " << n;
}
