#include <iostream>
#include <cstring>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n , m , a[N] , ans = 0;
bool flag[N];
signed main()
{
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    memset(flag , 1 , sizeof flag);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 30; i >= 0; i--)
    {
        int mul = 1 , cnt = 0;
        for(int j = 1; j <= i; j++) mul *= 2;
        for(int j = 1; j <= n; j++)
            if(flag[j] && (a[j] & mul)) cnt++;
        if(cnt >= m)
        {
            for(int j = 1; j <= n; j++)
            if((a[j] & mul) == 0) flag[j] = 0;
            ans += mul;
        }
    }
    cout << ans;
    return 0;
}
