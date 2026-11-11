#include <iostream>
using namespace std;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        ans=max(ans, k);
    }
    cout << ans;
    return 0;
}