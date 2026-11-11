#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int a[200005];
map<int, int> mp;
int count1(int n)
{
    int cnt = 0;
    while(n)
    {
        if(n % 2 == 1) cnt ++;
        n /= 2;
    }
    return cnt;
}
bool cmp(int x, int y)
{
    if(mp[x] != mp[y]) return mp[x] > mp[y];
    return x > y;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        mp[a[i]] = count1(a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    int ans = a[1];
    for(int i = 2; i <= m; i ++)
    {
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}