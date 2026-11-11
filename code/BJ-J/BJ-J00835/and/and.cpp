#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];
int main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1 , a + n + 1 , greater<int>());
    unsigned long long ans = 2147483647;
    for (int i = 1; i <= m; i ++) ans &= a[i];
    //for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    cout << ans;
}
