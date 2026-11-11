#include <bits/stdc++.h>
// #include <dragonpro.h>
using namespace std;
typedef long long ll;
typedef __int128_t i128;
namespace DRA_FASTIO
{
    #ifdef __linux__
        #define getch() getchar_unlocked()
        // #define putch() putchar_unlocked()
    #else
        #define getch() _getchar_nolock()
        // #define putch() _putchar_nolock()
    #endif
    inline void putch(char ch)
    {putchar_unlocked(ch); return;}
    inline ll get_int()
    {
        ll res = 0 , flag = 1;
        char c = getch();
        while(c < '0' || c > '9')
            flag = -1 , c = getch();
        while(c >= '0' && c <= '9')
            res = res * 10 + c - '0' , c = getch();
        return flag * res;
    }
    inline void put_int(ll number)
    {
        char ch[30] , top = 0;
        if(number < 0)
            putch('-') , number = -number;
        do ch[++ top] = number % 10 + '0' , number /= 10;
        while(number);
        while(top)
            putch(ch[top --]);
        return;
    }
}
using namespace DRA_FASTIO;
static constexpr int MAXN = 5e5 + 10;
ll n , m , a[MAXN]; i128 pre[MAXN];
inline bool check(int cur)
{   
    for(int i = cur ; i <= n ; i ++)  
        if(a[i] * cur <= (pre[i] - pre[i - cur - 1]) + m)
            return true;
    return false;
}
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    n = get_int() , m = get_int();
    for(int i = 1 ; i <= n ; i ++)
        a[i] = get_int();
    sort(a + 1 , a + n + 1);
    // for(int i = 1 ; i <= n ; i ++)
    //     put_int(a[i]) , putch(' ');
    // putch('\n');
    pre[0] = 0;
    for(int i = 1 ; i <= n ; i ++)
        pre[i] = pre[i - 1] + a[i];
    // for(int i = 1 ; i <= n ; i ++)
    //     put_int(pre[i]) , putch(' ');
    // putch('\n');
    ll l = 1 , r = n;
    // cout << l << " " << r << endl;
    while(l < r)
    {
        ll mid = (l + r + 1) >> 1;
        // cout << mid << endl;
        if(check(mid)) l = mid;
        else r = mid - 1;
        // cout << l <<" " << r << endl;
    }
    put_int(l) , putch('\n');
    return 0;
}
// dragonpro-presents