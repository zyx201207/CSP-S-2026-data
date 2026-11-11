#include <iostream>
#include <string>
#define int long long
using namespace std;

const int N = 2e5 + 5;
struct st
{
    int cnt;
    char c;
}a[N];
int n , sum = 0;
signed main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {cin >> a[i].cnt >> a[i].c;sum += a[i].cnt;}
    int l = 1 , r = n , ans = 0;
    while(l <= r)
    {
        if(l == r) break;
        if(a[l].cnt <= a[r].cnt)
        {
            if(a[l].c != a[r].c) ans += a[l].cnt;
            a[r].cnt -= a[l].cnt;l++;
            if(a[r].cnt == 0) r--;
        }
        else
        {
            if(a[l].c != a[r].c) ans += a[r].cnt;
            a[l].cnt -= a[r].cnt;r--;
            if(a[l].cnt == 0) l++;
        }
    }
    cout << ans;
    return 0;
}

