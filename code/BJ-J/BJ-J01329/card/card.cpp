#include <iostream>
#include <stack>
using namespace std;

const int N = 5e5 + 5;
int n , m , a[N] , cnt[N] , r[N] , ans[N];
signed main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {cin >> a[i];cnt[a[i]]++;r[a[i]] = i;}
    //for(int i = 1; i <= m; i++) cout << r[i] << " ";

    for(int i = 1; i <= m; i++)
    {
        ans[i] += cnt[i];
        int pos = r[i] + 1;
        while(pos <= n)
        {
            ans[a[pos]] += cnt[i];
            pos = r[a[pos]] + 1;
        }
    }

    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
