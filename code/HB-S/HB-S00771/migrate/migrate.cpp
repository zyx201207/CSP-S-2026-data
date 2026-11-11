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
static constexpr int MAXN = 2e6 + 10;
ll x[MAXN] , dist[MAXN];
int main()
{
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int testcase = get_int() , T = get_int();
    while(T --)
    {
        int n = get_int() , d = get_int();
        for(int i = 1 ; i <= n ; i ++)
            x[i] = get_int() , dist[i] = x[i] - x[i - 1];
        if(d >= x[n] - x[1])
        {put_int(0) , putch('\n'); continue;}
        else if(testcase >= 11 && testcase <= 12)
        {
            // cout << dist[n] << " " << d << endl;
            ll times = d / dist[n];
            if(times == 0) put_int(0) , putch('\n');
            else if(n - 2 * times + 1 < 0) put_int(0) , putch('\n');
            else put_int(n - 2 * times + 1) , putch('\n');
            continue;
        }
        // else if(testcase >= 13 && testcase <= 14)
        // {
        //     int l = 1 , r = n;
        //     while(l < r)
        //     {
        //         int mid = (l + r) >> 1;
        //         if(x[mid] - x[1] > d) r = mid - 1;
        //         else l = mid;
        //     }
        //     // l is the middle one
        //     for(int i = l ; i ; i --)
        //     {
                
        //     }
        //     continue;
        // }
    }
    return 0;
}
// dragonpro-presents